#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing customer details
struct Booking {
    char name[50];
    int roomNumber;
    int days;
    char roomType[20];
};

void displayRooms() {
    printf("\n========= Room Types =========\n");
    printf("1. Single Room - 1000 BDT/day\n");
    printf("2. Double Room - 1800 BDT/day\n");
    printf("3. Deluxe Room - 3000 BDT/day\n");
    printf("4. Suite Room  - 5000 BDT/day\n");
}

int getRoomPrice(char type[]) {
    if (strcmp(type, "1") == 0) return 1000;
    else if (strcmp(type, "2") == 0) return 1800;
    else if (strcmp(type, "3") == 0) return 3000;
    else if (strcmp(type, "4") == 0) return 5000;
    else return 0;
}

int main() {
    struct Booking b;
    int totalCost;

    printf("=================================\n");
    printf("     HOTEL ROOM BOOKING SYSTEM\n");
    printf("=================================\n");

    printf("\nEnter your name: ");
    fgets(b.name, sizeof(b.name), stdin);
    b.name[strcspn(b.name, "\n")] = 0;  // Remove newline

    displayRooms();

    printf("\nEnter Room Type (1/2/3/4): ");
    scanf("%s", b.roomType);

    printf("Enter Room Number (00-999): ");
    scanf("%d", &b.roomNumber);

    printf("Enter Number of Days to Stay: ");
    scanf("%d", &b.days);

    int price = getRoomPrice(b.roomType);
    if (price == 0) {
        printf("\nInvalid room type selected!\n");
        return 1;
    }

    totalCost = price * b.days;

    printf("\n======= Booking Confirmation =======\n");
    printf("Name       : %s\n", b.name);
    printf("Room No.   : %d\n", b.roomNumber);
    printf("Room Type  : %s\n", b.roomType);
    printf("Days Stay  : %d\n", b.days);
    printf("Total Cost : %d BDT\n", totalCost);
    printf("====================================\n");

    return 0;
}