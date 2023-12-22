#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100

int is_number(const char *word);
int is_alpha(const char *word);
int compare_words(const void *a, const void *b);
char *remove_duplicates(char *word);

int main() {
    char input_string[1000];
    char *words[MAX_WORDS];
    int word_count = 0;
    int number_sum = 0;
    int i;

    printf("Введите строку: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    char *token = strtok(input_string, " ");
    while (token != NULL && word_count < MAX_WORDS) {
        if (is_number(token)) {
            int num = atoi(token);
            if (num >= 10 && num <= 99) {
                number_sum += num;
            }
        } else if (is_alpha(token)) {
            words[word_count] = strdup(token);
            word_count++;
        }

        token = strtok(NULL, " ");
    }

    qsort(words, word_count, sizeof(char*), compare_words);

    for (i = 0; i < word_count; i++) {
        words[i] = remove_duplicates(words[i]);
    }


    printf("Сумма чисел от 10 до 99: %d\n", number_sum);
    printf("Слова без цифр в алфавитном порядке: ");
    for (i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }
    printf("\n");

    return 0;
}


int is_number(const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (isdigit(word[i])) {
            return 1;
        }
    }
    return 0;
}


int is_alpha(const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}


int compare_words(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}


char *remove_duplicates(char *word) {
    int len = strlen(word);
    int i, j;
    int unique_index = 0;


    for (i = 1; i < len; i++) {
        for (j = 0; j < i; j++) {
            if (word[i] == word[j]) {
                break;
            }
        }

        if (j == i) {
            word[++unique_index] = word[i];
        }
    }

    word[++unique_index] = '\0';
    return realloc(word, unique_index + 1);
}