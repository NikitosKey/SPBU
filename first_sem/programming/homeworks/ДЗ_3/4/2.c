//
// Created by Никита Морозов on 01.10.2023.
//

#include <stdio.h>

int sqr_digits_sum(int n);

int main(){
    int n, m;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter m: ");
    scanf("%d", &m);

    for (int i = 1; i < n; i++){
        if (sqr_digits_sum(i) < m)
            printf("%d\n", i);
    }

}

int sqr_digits_sum(int n){
    int sum = 0;
    while (n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum * sum;
}