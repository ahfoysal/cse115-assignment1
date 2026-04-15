#include <stdio.h>
#include <string.h>

struct tiffin {
    int orderID;
    char menu[30];
    int quantity;
    float price;
    char area[20];
};

int main() {
    struct tiffin o[6] = {
        {4501, "Hilsa Rice Combo", 1, 310, "Gulshan"},
        {4502, "Morog Polao", 2, 420, "Baridhara"},
        {4503, "Dal Rice Basic", 3, 210, "Shyamoli"},
        {4504, "Chicken Roast Meal", 1, 275, "Khilgaon"},
        {4505, "Veg Fried Rice", 2, 240, "Rampura"},
        {4506, "Beef Kacchi", 1, 380, "Motijheel"}
    };

    int i, j, key, found = 0;
    struct tiffin temp;

    printf("All Orders:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Menu: %s, Qty: %d, Price: %.2f Tk, Area: %s\n",
               o[i].orderID, o[i].menu, o[i].quantity, o[i].price, o[i].area);
    }

    printf("\nEnter order ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (o[i].orderID == key) {
            printf("Found: %d, %s, Qty %d, %.2f Tk, %s\n",
                   o[i].orderID, o[i].menu, o[i].quantity, o[i].price, o[i].area);
            found = 1;
        }
    }
    if (found == 0)
        printf("Order not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (o[j].price > o[j + 1].price) {
                temp = o[j];
                o[j] = o[j + 1];
                o[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by price:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Menu: %s, Qty: %d, Price: %.2f Tk, Area: %s\n",
               o[i].orderID, o[i].menu, o[i].quantity, o[i].price, o[i].area);
    }

    return 0;
}
