#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int has_substring_and_digit(const char *word, const char *substring);
int compare_numbers(const void *a, const void *b);

int main() {
    char input_string[1000];
    char *words[MAX_WORDS];
    int word_count = 0;
    int matching_word_count = 0;
    int numbers[MAX_WORDS];
    int number_count = 0;
    int i;

    printf("Введите строку: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    printf("Введите цепочку символов: ");
    char substring[MAX_WORD_LENGTH];
    scanf("%s", substring);

    char *token = strtok(input_string, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        if (has_substring_and_digit(token, substring)) {
            words[matching_word_count] = strdup(token);
            matching_word_count++;

            int number = atoi(token);
            if (number != 0) {
                numbers[number_count] = number;
                number_count++;
            }
        }

        token = strtok(NULL, " ");
    }
    printf("Числа, встретившиеся в отобранных словах (в порядке возрастания): ");
    qsort(numbers, number_count, sizeof(int), compare_numbers);
    for (i = 0; i < number_count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");



    printf("Слова, содержащие цепочку %s и хотя бы одну цифру: ", substring);
    for (i = 0; i < matching_word_count; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }
    printf("\n");



    printf("Количество слов, содержащих цепочку %s и хотя бы одну цифру: %d\n", substring, matching_word_count);

    return 0;
}

int has_substring_and_digit(const char *word, const char *substring) {
    int has_digit = 0;
    int has_substring = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (isdigit(word[i])) {
            has_digit = 1;
        }

        if (strstr(word, substring) != NULL) {
            has_substring = 1;
        }
    }

    return has_digit && has_substring;
}


int compare_numbers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}