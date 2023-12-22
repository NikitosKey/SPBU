#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Функция для вывода перевернутого слова, если найдены цепочки
void printReversedWord(char* word) {
    char reversedWord[100];
    int length = strlen(word);

    // Если длина слова не превышает 6 символов, и оно состоит только из больших букв, выводим перевернутое слово
    if (length <= 6) {
        int isUpperCase = 1;
        for (int i = 0; i < length; i++) {
            if (!isupper(word[i])) {
                isUpperCase = 0;
                break;
            }
        }

        if (isUpperCase) {
            for (int i = length - 1, j = 0; i >= 0; i--, j++) {
                reversedWord[j] = word[i];
            }
            reversedWord[length] = '\0';
            printf("Original: %s, Reversed: %s\n", word, reversedWord);
        }
    }
}

int main() {
    char input_text[500];
    printf("Введите текст: ");
    fgets(input_text, sizeof(input_text), stdin);

    char* token = strtok(input_text, " \t\n");

    while (token != NULL) {
        // Проверяем, состоит ли слово только из больших букв
        int isUpperCase = 1;
        for (int i = 0; i < strlen(token); i++) {
            if (!isupper(token[i])) {
                isUpperCase = 0;
                break;
            }
        }

        // Если слово состоит только из больших букв, ищем цепочки
        if (isUpperCase) {
            printReversedWord(token);
        }

        // Получаем следующее слово
        token = strtok(NULL, " \t\n");
    }

    return 0;
}
