//
// Created by Никита Морозов on 03.11.2023.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Task2.h"



int Task_2() {
    printf("\t\t**Block tape matrices pro edition V1.0.0**\n");

    printf("Enter the matrix order (It should be more than 9 and be multiple of three): ");
    int m = 0;
    scanf("%d", &m);

    if (m % 3 != 0 || m < 9){
        printf("You couldn't create matrix with this matrix order :( Try again.\n");
        printf("Press enter...\n");
        getchar();
        return 0;
    }


    int **matrix = create(m);


    printf("Enter the matrix coordinates separated by space: ");
    int x, y;
    scanf("%d %d", &x, &y);

    int result = access(matrix, m, x, y);
    printf("%d\n", result);


    destroy(matrix, m);

    printf("Press enter...\n");
    getchar();
    return 0;
}


int** create(CREATE_ARGS) {
    printf("Creating matrix...\n");

    int **matrix = (int **) malloc((m_order + 2) * sizeof(int *));

//    length_arr
    matrix[m_order+1] = (int *) malloc(m_order * sizeof(int));
//    shifts_arr
    matrix[m_order+2] = (int *) malloc(m_order * sizeof(int));

    int m_line_len = 9;
    int shift = 0;

    for (int i = 0; i < m_order; i++){
//        if new block
        if ((i + 1) % 3 == 0 && m_line_len < 15)
            m_line_len += 3;

//        Shifting
        if ((i + 1) >= 9 && (i + 1) % 3 == 0)
            shift += 3;

//        Allocation taking into account the shift and matrix order
        if (m_line_len + shift < m_order)
            matrix[i] = (int *) malloc(m_line_len * sizeof(int));
        else
            matrix[i] = (int *) malloc(((m_line_len - (m_line_len + shift) % m_order)) * sizeof(int));

//        Filling rand for example
        srand(time(NULL));
        for (int j = 0; j < m_line_len; j++){
            matrix[i][j] = rand();
        }

//        Saving shift and length
        matrix[m_order+1][i] = m_line_len;
        matrix[m_order+2][i] = shift;
    }
    return matrix;
}


int access(ACCESS_ARGS){
    if (row > m_order || col > m_order)
        return 0;

    if (col < matrix[m_order+2][row])
        return 0;

    int available = matrix[m_order+2][row] + matrix[m_order+1][row];

    if (col > available)
        return 0;


    return matrix[row][col - matrix[m_order+2][row]];
}


void destroy(DESTROY_ARGS) {
    printf("Destroying matrix...\n");

    for (int i = 0; i < m_order+2; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);
    matrix = NULL;
}

