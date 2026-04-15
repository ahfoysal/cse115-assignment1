#include <stdio.h>
#include <string.h>

struct cake {
    int orderID;
    char flavor[20];
    float size;
    float price;
    char decoration[25];
    char pickup[10];
};

int main() {
    struct cake c[6] = {
        {7701, "Chocolate", 1.0, 850, "Rose topping", "05:00PM"},
        {7702, "Vanilla", 0.5, 450, "Happy Birthday", "11:00AM"},
        {7703, "RedVelvet", 2.0, 1800, "Gold foil", "07:30PM"},
        {7704, "Blackforest", 1.5, 1250, "Cherry cluster", "02:45PM"},
        {7705, "Strawberry", 1.0, 950, "Fruit slices", "06:15PM"},
        {7706, "Cheesecake", 0.8, 780, "Caramel drizzle", "04:00PM"}
    };

    int i, j, key, found = 0;
    struct cake temp;

    printf("All Cake Orders:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Flavor: %s, Size: %.2f kg, Price: %.2f Tk, Decoration: %s, Pickup: %s\n",
               c[i].orderID, c[i].flavor, c[i].size, c[i].price, c[i].decoration, c[i].pickup);
    }

    printf("\nEnter order ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (c[i].orderID == key) {
            printf("Found: %d, %s, %.2f kg, %.2f Tk, %s, %s\n",
                   c[i].orderID, c[i].flavor, c[i].size, c[i].price, c[i].decoration, c[i].pickup);
            found = 1;
        }
    }
    if (found == 0)
        printf("Order not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (c[j].price > c[j + 1].price) {
                temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by price:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Flavor: %s, Size: %.2f kg, Price: %.2f Tk, Decoration: %s, Pickup: %s\n",
               c[i].orderID, c[i].flavor, c[i].size, c[i].price, c[i].decoration, c[i].pickup);
    }

    return 0;
}
