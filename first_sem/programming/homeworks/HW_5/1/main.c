#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* to_bin(int n) {
    int n2 = n, c = 0;

    while (n2 != 0){
        n2 /= 2;
        c++;
    }

    char* buff = malloc(sizeof(int) * c);
    c--;
    while (n != 0) {
        buff[c] = (n % 2) + '0';
        n /= 2;
        c--;
    }
    return buff;
}

int main() {
    char* bin_n = NULL;
    int i, n;
    printf("Enter n: ");
    scanf("%d", &n);
     printf("Enter i: ");
    while(getchar()!='\n');
    scanf("%d", &i);
    void *nullptr = NULL;
    /* //for windows
    bin_n = itoa(n, bin_n, 2);
    strcpy(bin_n, to_bin(n));*/

    bin_n = to_bin(n);
    switch (bin_n[i]) {
        case '1':
            bin_n[i] = '0';
            break;
        case '0':
            bin_n[i] = '1';
            break;
        default:
            printf("Incorrect data.\n");
            exit(0);
    }
    int result = (int) strtol(bin_n, nullptr, 2);
    printf("%d", result);
    return 0;
}
