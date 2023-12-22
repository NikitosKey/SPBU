#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    int N;
    printf("Введите количество строк N: ");
    scanf("%d", &N);

    // Создание и запись в файл f
    FILE* file_f = fopen("f.txt", "w");
    if (file_f == NULL) {
        printf("Не удалось открыть файл f.txt для записи.\n");
        return 1;
    }

    printf("Введите %d строк:\n", N);
    getchar();

    char buffer[MAX_LENGTH];
    size_t length;

    for (int i = 0; i < N; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        length = strlen(buffer);

        fputs(buffer, file_f);

        if (length % 2 == 0) {
            FILE* file_d = fopen("d.txt", "a");
            if (file_d == NULL) {
                printf("Не удалось открыть файл d.txt для записи.\n");
                fclose(file_f);
                return 1;
            }
            fputs(buffer, file_d);
            fclose(file_d);
        } else {
            FILE* file_h = fopen("h.txt", "a");
            if (file_h == NULL) {
                printf("Не удалось открыть файл h.txt для записи.\n");
                fclose(file_f);
                return 1;
            }
            fputs(buffer, file_h);
            fclose(file_h);
        }
    }

    fclose(file_f);
    printf("Файлы успешно созданы.\n");

    return 0;
}
