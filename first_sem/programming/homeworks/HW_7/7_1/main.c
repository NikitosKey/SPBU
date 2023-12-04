//
// Created by Никита Морозов on 03.11.2023.
//


#include <stdio.h>
#include <stdlib.h>
#include "Tasks.h"

int main(){
    printf("Chose the task\n1) Task 1\n2) Task 2\nOther key) End the program\n");
    char c;
    scanf("%c", &c);
    switch (c) {
        case '1':
            Task_1();
            while (getchar() != '\n');
            main();
            break;
        case '2':
            while (getchar() != '\n');
            main();
            break;
        default:
            exit(0);
    }
}