#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = (char *) malloc(1000);
    gets(str);

    return 0;
}
