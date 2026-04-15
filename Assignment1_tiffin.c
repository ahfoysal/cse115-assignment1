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
        {4611, "Prawn Curry Box", 1, 340, "Niketan"},
        {4612, "Khichuri Special", 2, 360, "Nikunja"},
        {4613, "Chicken Grill Rice", 1, 290, "Lalmatia"},
        {4614, "Tuna Salad Bowl", 1, 255, "Dhanmondi"},
        {4615, "Paneer Rice Combo", 2, 320, "Panthapath"},
        {4616, "Mixed Kebab Platter", 1, 410, "Kakrail"}
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
