#include <stdio.h>
#include <stdlib.h>

int binarySearchLastOccurrence(int* arr, int length, int target) {
    int low = 0, high = length - 1;
    int result = -1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            low = mid + 1;
            result = mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (arr[mid] == target) return 0;

    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6}; // мне лень заполнять динамичкский
    int length = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarySearchLastOccurrence(arr, length, target);

    if (result != -1) {
        printf("Последний элемент %d в массиве с индексом %d.\n", target, result);
    } else {
        printf("Элемент %d не найден в массиве.\n", target);
    }

    return 0;
}

