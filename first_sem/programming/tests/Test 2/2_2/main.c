#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char **strings = NULL;
    char input[MAX_STRING_LENGTH];
    int numStrings = 0;

    printf("Введите строки (введите 'end' для завершения ввода):\n");
    while (1) {
        printf("Строка %d: ", numStrings + 1);
        fgets(input, MAX_STRING_LENGTH, stdin);

        if (strcmp(input, "end\n") == 0) {
            break;
        }

        strings = (char **)realloc(strings, (numStrings + 1) * sizeof(char *));
        strings[numStrings] = (char *)malloc(strlen(input) + 1);

        strcpy(strings[numStrings], input);

        numStrings++;
    }

    printf("\nСконкатенированные строки:\n");
    for (int i = 0; i < numStrings / 2; i++) {
        char *concatenatedString = (char *)malloc(strlen(strings[i]) + strlen(strings[numStrings - 1 - i]) + 1);
        strcpy(concatenatedString, strings[i]);
        strcat(concatenatedString, strings[numStrings - 1 - i]);

        printf("%s\n", concatenatedString);

        free(concatenatedString);
    }

    for (int i = 0; i < numStrings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}