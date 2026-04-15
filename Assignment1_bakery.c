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
        {7811, "Mocha Fudge", 1.2, 920, "Coffee beans", "04:30PM"},
        {7812, "Butterscotch", 0.6, 520, "Toffee bits", "12:00PM"},
        {7813, "Tiramisu", 1.8, 1650, "Cocoa dust", "08:00PM"},
        {7814, "Pineapple", 1.3, 1100, "Fruit chunks", "03:15PM"},
        {7815, "Lemon Tart", 0.9, 870, "Citrus zest", "05:45PM"},
        {7816, "Mango Mousse", 1.0, 960, "Mango slices", "06:30PM"}
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
