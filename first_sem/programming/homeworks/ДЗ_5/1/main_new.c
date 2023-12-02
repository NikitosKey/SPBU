#include <stdio.h>
int count_sig_bin_dig(int n){
    int n2 = n, c = 0;

    //Count of significant binary digits
    while (n2 != 0) {
        n2 /= 2;
            c++;
    }
    return c;
}

void print_bin(int n) {
    int c = count_sig_bin_dig(n), count_of_groups = c / 4 + 1;

    for (int i = count_of_groups; i > 0; i--) {
        for (int j = 3; j >= 0; j--){
            int pos = (i - 1) * 4 + j;
            printf("%d", (n >> pos) & 1);
        }
        printf(" ");
    }
    printf("\n");
}


int main() {
    int i, n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter i: ");
    while(getchar()!='\n');
    scanf("%d", &i);

    print_bin(n);

    n = n ^ (1 << i);

    print_bin(n);

    printf("%d", n);
    return 0;
}
