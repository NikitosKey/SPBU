//
// Created by Никита Морозов on 03.11.2023.
//

#define CREATE_ARGS const int m_order
#define ACCESS_ARGS const int **matrix, const int m_order, const int row, const int col
#define DESTROY_ARGS int **matrix, const int m_order

int** create(CREATE_ARGS);

int access(ACCESS_ARGS);

void destroy(DESTROY_ARGS);
