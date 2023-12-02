//
// Created by Никита Морозов on 23.09.2023.
//

void cls(void);
void clear(void);
#include <locale.h>


#if defined(_WIN64)
#define sys_clear system("cls")
#elif defined(__linux__) || defined(__APPLE__)
#define sys_clear system("clear")
#endif