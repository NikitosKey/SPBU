#include <stdio.h>

struct DATE {
    unsigned year : 3;
    unsigned month : 4;
    unsigned day : 5;
};

struct MARSHRUT {
    int NUM;
    struct DATE BEGIN;
    char FROM[100];
    char TO[100];
    float LENGTH;
};

void printAllMarshruts(struct MARSHRUT marshruts[], int size){
    for (int i = 0; i < size; i++){
        printf("Номер маршрута: %d\nГод введения: %d\nМесяц введения: %d\nДень введения: %d\nНачальный пункт: %s\nКонечный пункт: %s\nДлина маршрута: %d\n",\
        marshruts[i].NUM, marshruts[i].BEGIN.year + 2018, marshruts[i].BEGIN.month, marshruts[i].BEGIN.day, marshruts[i].FROM,\
        marshruts[i].TO, marshruts[i].LENGTH);
    }
}

void createMarshrut(struct MARSHRUT marshruts[], int size) {
    for (int i = 0; i < size; i++) {
       int year, month, day;
        printf("Введите данные для маршрута #%d:\n", i + 1);

        printf("Номер маршрута: ");
        scanf("%d", &marshruts[i].NUM);

        printf("Год введения (0-5): ");
        scanf("%d", &year);
        marshruts[i].BEGIN.year = year;
        //marshruts[i].BEGIN.year += 2018;

        printf("Месяц введения (1-12): ");
        scanf("%d", &month);
        marshruts[i].BEGIN.month = month;

        printf("Число введения (1-31): ");
        scanf("%d", &day);
        marshruts[i].BEGIN.day = day;

        printf("Начальный пункт маршрута: ");
        scanf("%s", marshruts[i].FROM);

        printf("Конечный пункт маршрута: ");
        scanf("%s", marshruts[i].TO);

        printf("Длина маршрута: ");
        scanf("%f", &marshruts[i].LENGTH);

        printf("\n");
    }
}

int findLongestMarshrut(struct MARSHRUT marshruts[], int size) {
    int maxIndex = 0;
    float maxLength = marshruts[0].LENGTH;

    for (int i = 1; i < size; i++) {
        if (marshruts[i].LENGTH > maxLength) {
            maxLength = marshruts[i].LENGTH;
            maxIndex = i;
        }
    }

    return maxIndex;
}



void sortMarshrutsByNumber(struct MARSHRUT marshruts[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (marshruts[j].NUM < marshruts[i].NUM) {
                struct MARSHRUT temp = marshruts[i];
                marshruts[i] = marshruts[j];
                marshruts[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Введите количество маршрутов: ");
    scanf("%d", &size);

    struct MARSHRUT marshruts[size];

    createMarshrut(marshruts, size);

    int choice;
    printf("Выберите действие:\n");
    printf("1 - Найти маршрут с максимальной длиной\n");
    printf("2 - Расположить записи по возрастанию номеров маршрутов\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int maxIndex = findLongestMarshrut(marshruts, size);
            printf("Маршрут с максимальной длиной: #%d\n", marshruts[maxIndex].NUM);
            break;
        }
        case 2:
            sortMarshrutsByNumber(marshruts, size);
            printf("Записи расположены по возрастанию номеров маршрутов.\n");
            printAllMarshruts(marshruts, size);
            break;
        default:
            printf("Некорректный выбор.\n");
    }
    return 0;
    }