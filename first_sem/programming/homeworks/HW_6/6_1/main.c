#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int getNextPrime() {
    static int currentPrime = 1;

    while (1) {
        currentPrime++;

        if (isPrime(currentPrime)) {
            return currentPrime;
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d ", getNextPrime());
    }

    return 1;
}