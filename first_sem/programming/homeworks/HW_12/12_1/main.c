#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define SEARCH_STRING_MAX_LENGTH 100

void printStrings(const char** strings, int count, FILE* f) {
    for (int i = 0; i < count; i++) {
        fprintf(f, "%s\n", strings[i]);
    }
}

void checkAndPrintStrings(const char** strings, const char* search, int count, FILE* f){
    fprintf(f, "Строки, в которых нет символов из строки \"%s\":\n", search);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strpbrk(strings[i], search) == NULL) {
            fprintf(f, "%s\n", strings[i]);
            found = 1;
        }
    }

    if (!found) {
        fprintf(f, "Таких строк нет.\n");
    }

    printf("\nОстальные строки:\n");
    printStrings(strings, count, f);
}

int main() {
    int numStrings = 0;
    char** strings = NULL;

    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        return 1;
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, sizeof(buffer), inputFile)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "end") == 0) {
            break;
        }

        numStrings++;

        char** temp = realloc(strings, numStrings * sizeof(char*));
        if (temp == NULL) {
            printf("Ошибка выделения памяти.\n");
            return 1;
        }
        strings = temp;

        strings[numStrings - 1] = malloc((strlen(buffer) + 1) * sizeof(char));
        if (strings[numStrings - 1] == NULL) {
            printf("Ошибка выделения памяти.\n");
            return 1;
        }
        strcpy(strings[numStrings - 1], buffer);
    }

    fclose(inputFile);

    char search[SEARCH_STRING_MAX_LENGTH];
    FILE* searchFile = fopen("search.txt", "r");
    if (searchFile == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        return 1;
    }

    if (fgets(search, sizeof(search), searchFile) == 0) {
        printf("Ошибка чтения строки для поиска.\n");
        return 1;
    }
    search[strcspn(search, "\n")] = '\0';

    fclose(searchFile);

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Не удалось открыть файл для записи.\n");
        return 1;
    }

/*    fprintf(outputFile, "Все строки:\n");
    printStrings(strings, numStrings);*/

    fprintf(outputFile, "\n");
    checkAndPrintStrings((const char**)strings, search, numStrings, outputFile);

    fclose(outputFile);

    for (int i = 0; i < numStrings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}