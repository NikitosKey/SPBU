#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Task1.h"


int Task_1() {
    size_t str1_size = 1, str2_size = 1;
    char *str1, *str2;
    input_string(&str1, &str1_size);
    input_string(&str2, &str2_size);

    size_t symbols1_size = 1, symbols2_size = 1;
    char *symbols1, *symbols2;
    int *count_of_symbols1, *count_of_symbols2;

    counting(str1, &symbols1, &count_of_symbols1, &symbols1_size, str1_size);
    counting(str2, &symbols2, &count_of_symbols2, &symbols2_size, str2_size);
    compare(symbols1, symbols2, count_of_symbols1, count_of_symbols2, symbols1_size, symbols2_size);

    printf("Press enter...\n");
    getchar();
    return 0;
}


void input_string(INPUT_ARGS) {
    while (getchar() != '\n');

    char *string = (char *) malloc(200);
    printf("Enter the string: ");
    char c = '0';

    while (c != '.') {
        c = getchar();
        string[(*size) - 1] = c;
        *size = (*size) + 1;
    }
    string[*size] = '\0';
    printf("\n");

    *str = string;
}


void counting(COUNTING_ARGS) {
    int *count = malloc(1000 * sizeof(int));
    char *syms = (char *) malloc(1000);

    for (int i = 0; i < str_size - 1; i++) {
        if (str[i] != ' ') {
            bool flag = false;
            int j;
            for (j = 0; j < (*symbols_size) - 1; j++) {
                if (str[i] == syms[j]) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                count[j]++;
            } else {
                (*symbols_size)++;
                syms[j] = str[i];
                count[j] = 1;
            }
        }
    }

    //Maybe I shouldn't to do it.
    count = (int *) realloc(count, 1000 * sizeof(int) - (1000 * sizeof(int) - strlen(syms) * sizeof(int)));
    syms = (char *) realloc(syms, 1000 - (1000 - strlen(syms)));


    *symbols = syms;
    *count_of_symbols = count;
}


void compare(COMPARE_ARGS) {
    if (size1 == size2) {
        bool flag = false;
        for (int i = 0; i < size1 - 1; i++) {
            int j;
            for (j = 0; j < size1 - 1; j++) {
                if (symbols1[i] == symbols2[j]) {
                    flag = true;
                    break;
                }
            }
            if (!flag || (flag && (count_of_symbols1[i] != count_of_symbols2[j]))) {
                printf("This strings cannot be get by permutations.\n");
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Success\n");
    } else {
        printf("This strings cannot be get by permutations.\n");
    }
}