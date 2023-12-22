#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int frequency;
    int ram_size;
    unsigned dvd_rom :1;
    int price;
} Computer;

Computer Filling_computer_info();

void Print_computer_info(Computer Current_comp);

int main() {
    int arr_size;
    scanf("%d", &arr_size);

    Computer Arr[arr_size];

    for (int i = 0; i < arr_size; i++) {
        Arr[i] = Filling_computer_info();
    }

    for (int i = 0; i < arr_size; i++) {
        if(Arr[i].ram_size > 10240)
            Print_computer_info(Arr[i]);
    }

    return 0;
}

Computer Filling_computer_info() {
    Computer New_comp;

    printf("Enter the computer name: ");
    scanf("%s", New_comp.name);
    printf("\n");

    printf("Enter the computer's CPU frequency (MHz): ");
    scanf("%d", &New_comp.frequency);
    printf("\n");

    printf("Enter the computer's RAM size (MB): ");
    scanf("%d", &New_comp.ram_size);
    printf("\n");

    printf("Enter the computer's price (RUB): ");
    scanf("%d", &New_comp.price);
    printf("\n");

    while (getchar() != '\n');
    printf("DVD ROM availability (y/n): ");
    char c;
    scanf("%c", &c);

    switch (c) {
        case 'Y':
        case 'y':
            New_comp.dvd_rom = 1;
            break;
        default:
            New_comp.dvd_rom = 0;
    }
    printf("\n");

    return New_comp;
}

void Print_computer_info(Computer Current_comp) {
    printf("name: %s\nFrequency: %d MHz\nRAM size: %d MB\nPrice: %d RUB\n", Current_comp.name,
           Current_comp.frequency, Current_comp.ram_size, Current_comp.price);
    printf("DVD ROM: ");
    if (Current_comp.dvd_rom)
        printf("Yes");
    else
        printf("No");
}