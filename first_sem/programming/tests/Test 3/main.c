#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_BIKES 1000

typedef enum {
    CHILD,
    TEENAGER,
    ROAD,
    SPORT
} BikeType;

typedef struct {
    int warranty_period;
    char arrival_date[20];
    int quantity_in_stock;
    float price;
    int is_active;
} BikeCharacteristics;

typedef struct {
    BikeType type;
    char model[50];
    BikeCharacteristics characteristics;

    union {
        struct {
            int wheel_count;
            int front_wheel_radius;
            int rear_wheel_radius;
        } child;

        struct {
            int wheel_radius;
            int gears_count;
        } teenager;

        struct {
            float weight;
            float tire_width;
            char frame_material[30];
        } sport;

        struct {
            int has_suspension;
            int has_hand_brake;
        } road;
    };
} Bicycle;

void initializeBikes(Bicycle bikes[], int size) {
    for (int i = 0; i < size; ++i) {
        bikes[i].characteristics.is_active = 0;
    }
}

void acceptBikesFromFile(Bicycle bikes[], int size, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    for (int i = 0; i < size; ++i) {
        int type;
        char model[50];
        int warranty_period;
        char arrival_date[20];
        int quantity_in_stock;
        float price;
        int is_active;
        fscanf(file, "%d", &type);
        bikes[i].type = (BikeType)type;

        fscanf(file, "%s %d %s %d %f %d",
               model,
               &warranty_period,
               arrival_date,
               &quantity_in_stock,
               &price,
               &is_active);
        bikes[i].characteristics.is_active = 1;
        strcpy(bikes[i].model, model);
        bikes[i].characteristics.warranty_period = warranty_period;
        strcpy(bikes[i].characteristics.arrival_date, arrival_date);
        bikes[i].characteristics.quantity_in_stock = quantity_in_stock;
        bikes[i].characteristics.price = price;

        switch (bikes[i].type) {
            case CHILD:
                fscanf(file, " %d %d %d",
                       &bikes[i].child.wheel_count,
                       &bikes[i].child.front_wheel_radius,
                       &bikes[i].child.rear_wheel_radius);
                break;

            case TEENAGER:
                fscanf(file, "%d %d",
                       &bikes[i].teenager.wheel_radius,
                       &bikes[i].teenager.gears_count);
                break;

            case ROAD:
                fscanf(file, "%d %d",
                       &bikes[i].road.has_suspension,
                       &bikes[i].road.has_hand_brake);
                break;

            case SPORT:
                fscanf(file, "%f %f %s",
                       &bikes[i].sport.weight,
                       &bikes[i].sport.tire_width,
                       bikes[i].sport.frame_material);
                break;

            default:
                printf("Unknown bike type.\n");
                break;
        }
    }

    fclose(file);
}

void findSportBikeByCriteria(Bicycle bikes[], int size, const char* material, const char* model, float maxWeight) {
    for (int i = 0; i < size; ++i) {
        if (bikes[i].characteristics.is_active &&
            (strcmp(bikes[i].model, model) == 0 ||
            strcmp(bikes[i].sport.frame_material, material) == 0) &&
            bikes[i].sport.weight <= maxWeight &&
            bikes[i].type == SPORT) {
            printf("Found sport bike:\n");
            printf("Type: SPORT\nModel: %s\nWeight: %.2f\nTire Width: %.2f\nFrame Material: %s\nPrice: %.2f\n",
                   bikes[i].model, bikes[i].sport.weight, bikes[i].sport.tire_width, bikes[i].sport.frame_material, bikes[i].characteristics.price);
            return;
        }
    }
    printf("Sport bike not found with the specified criteria.\n");
}

void changeChildBikePrice(Bicycle bikes[], int size, const char* model, int wheelCount, float priceChange) {
    for (int i = 0; i < size; ++i) {
        if (bikes[i].characteristics.is_active &&
            bikes[i].type == CHILD &&
            strcmp(bikes[i].model, model) == 0 &&
            bikes[i].child.wheel_count == wheelCount) {
            printf("%f", bikes[i].characteristics.price);
            bikes[i].characteristics.price += priceChange;
            printf("Price for child bike '%s' with %d wheels changed.\n%f\n", model, wheelCount,  bikes[i].characteristics.price);
        }
    }
    printf("Child bike not found with the specified criteria.\n");
}

int dateToDays(const char* date) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);

    int days = day;
    for (int i = 1; i < month; ++i) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days += 31;
                break;
            case 4: case 6: case 9: case 11:
                days += 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                    days += 29;
                else
                    days += 28;
                break;
            default:
                return -1;
        }
    }

    return days;
}

// Функция для сравнения двух дат
int compareDates(const char* date1, const char* date2) {
    int days1 = dateToDays(date1);
    int days2 = dateToDays(date2);

    if (days1 == -1 || days2 == -1) {
        // Некорректные даты
        return 0;
    }

    return days1 - days2;
}

// Функция для получения текущей даты в формате yyyy-mm-dd
void getCurrentDate(char* currentDate) {
    time_t t;
    struct tm* tm_info;

    time(&t);
    tm_info = localtime(&t);

    strftime(currentDate, 20, "%Y-%m-%d", tm_info);
}

// ... (остальной код)

void retireTeenagerBikes(Bicycle bikes[], int size) {
    char currentDate[20];
    getCurrentDate(currentDate);

    for (int i = 0; i < size; ++i) {
        if (bikes[i].characteristics.is_active &&
            bikes[i].type == TEENAGER) {

            int arrivalPlusWarrantyDays = dateToDays(bikes[i].characteristics.arrival_date) + bikes[i].characteristics.warranty_period;
            int currentDateDays = dateToDays(currentDate);

            if (compareDates(currentDate, bikes[i].characteristics.arrival_date) > 0 && currentDateDays >= arrivalPlusWarrantyDays) {
                bikes[i].characteristics.is_active = 0;
                printf("Teenager bike '%s' retired.\n", bikes[i].model);
            }
        }
    }
}

void printRoadBikesWithSuspension(Bicycle bikes[], int size, FILE* f) {
    for (int i = 0; i < size; ++i) {
        if (bikes[i].characteristics.is_active &&
            bikes[i].type == ROAD &&
            bikes[i].road.has_suspension &&
            bikes[i].road.has_hand_brake) {
            fprintf(f, "Road bike: Model - %s, Price - %.2f\n", bikes[i].model, bikes[i].characteristics.price);
        }
    }
}

void printWarehouseContents(Bicycle bikes[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (bikes[i].characteristics.is_active) {
            printf("Type: %d\n", bikes[i].type);
            printf("Model: %s\n", bikes[i].model);
            printf("Warranty Period: %d days\n", bikes[i].characteristics.warranty_period);
            printf("Arrival Date: %s\n", bikes[i].characteristics.arrival_date);
            printf("Quantity in Stock: %d\n", bikes[i].characteristics.quantity_in_stock);
            printf("Price: %.2f\n", bikes[i].characteristics.price);

            switch (bikes[i].type) {
                case CHILD:
                    printf("Wheel Count: %d\n", bikes[i].child.wheel_count);
                    printf("Front Wheel Radius: %d\n", bikes[i].child.front_wheel_radius);
                    printf("Rear Wheel Radius: %d\n", bikes[i].child.rear_wheel_radius);
                    break;

                case TEENAGER:
                    printf("Wheel Radius: %d\n", bikes[i].teenager.wheel_radius);
                    printf("Gears Count: %d\n", bikes[i].teenager.gears_count);
                    break;

                case ROAD:
                    printf("Has Suspension: %d\n", bikes[i].road.has_suspension);
                    printf("Has Hand Brake: %d\n", bikes[i].road.has_hand_brake);
                    break;

                case SPORT:
                    printf("Weight: %.2f\n", bikes[i].sport.weight);
                    printf("Tire Width: %.2f\n", bikes[i].sport.tire_width);
                    printf("Frame Material: %s\n", bikes[i].sport.frame_material);
                    break;

                default:
                    printf("Unknown bike type.\n");
                    break;
            }
            count++;
            printf("%d\n", count);
            printf("----------------------------\n");
        }
    }
}

int main() {
    Bicycle warehouse[MAX_BIKES];
    initializeBikes(warehouse, MAX_BIKES);

    int choice;
    char currentDate[20];

    do {
        getCurrentDate(currentDate);
        printf("1. Accept bikes from file\n");
        printf("2. Find sport bike by criteria\n");
        printf("3. Change child bike price\n");
        printf("4. Retire teenager bikes\n");
        printf("5. Print road bikes with suspension\n");
        printf("6. Print warehouse contents\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        FILE *out = fopen("output.txt", "a");
        switch (choice) {

            case 1:
                acceptBikesFromFile(warehouse, MAX_BIKES, "bikes.txt");
                break;

            case 2:
                findSportBikeByCriteria(warehouse, MAX_BIKES, "Steel", "Model944", 15.0f);
                break;

            case 3:
                changeChildBikePrice(warehouse, MAX_BIKES, "Model774", 3, -100.0f);
                break;

            case 4:
                retireTeenagerBikes(warehouse, MAX_BIKES);
                break;

            case 5:
                if (out == NULL) {
                    perror("Error opening file");
                    return 1;
                }
                printRoadBikesWithSuspension(warehouse, MAX_BIKES, out);
                break;

            case 6:
                printWarehouseContents(warehouse, MAX_BIKES);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 0 and 6.\n");
        }
        fclose(out);
    } while (choice != 0);


    return 0;
}
