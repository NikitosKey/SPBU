//
// Created by Никита Морозов on 03.11.2023.
//
#define INPUT_ARGS char** str, size_t* size
#define UNLUCK_ARGS void
#define COUNTING_ARGS const char* str, char** symbols, int** count_of_symbols, size_t* symbols_size, size_t str_size
#define COMPARE_ARGS const char* symbols1, const char* symbols2, const int* count_of_symbols1, const int* count_of_symbols2, const size_t size1, const size_t size2


void input_string(INPUT_ARGS);

void unluck(UNLUCK_ARGS);

void counting(COUNTING_ARGS);

void compare(COMPARE_ARGS);

void print_array(int *arr, size_t size);