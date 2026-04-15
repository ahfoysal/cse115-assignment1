#include <stdio.h>
#include <string.h>

struct sale {
    int saleID;
    char item[20];
    int quantity;
    float unitPrice;
    char payment[10];
    char spot[15];
};

int main() {
    struct sale s[6] = {
        {101, "Burger", 2, 180, "Cash", "Dhanmondi-27"},
        {102, "Shawarma", 4, 150, "bKash", "Banani-11"},
        {103, "Pasta", 1, 220, "Card", "Gulshan-2"},
        {104, "Fries", 3, 80, "Cash", "Uttara-4"},
        {105, "HotDog", 2, 130, "bKash", "Mirpur-10"},
        {106, "ChickenWrap", 5, 170, "Card", "Bashundhara"}
    };

    int i, j, key, found = 0;
    struct sale temp;
    float a, b;

    printf("All Sales:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Item: %s, Qty: %d, Unit: %.2f Tk, Payment: %s, Spot: %s, Total: %.2f Tk\n",
               s[i].saleID, s[i].item, s[i].quantity, s[i].unitPrice, s[i].payment, s[i].spot,
               s[i].quantity * s[i].unitPrice);
    }

    printf("\nEnter sale ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (s[i].saleID == key) {
            printf("Found: %d, %s, Qty %d, %.2f Tk, %s, %s, Total %.2f Tk\n",
                   s[i].saleID, s[i].item, s[i].quantity, s[i].unitPrice, s[i].payment, s[i].spot,
                   s[i].quantity * s[i].unitPrice);
            found = 1;
        }
    }
    if (found == 0)
        printf("Sale not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            a = s[j].quantity * s[j].unitPrice;
            b = s[j + 1].quantity * s[j + 1].unitPrice;
            if (a > b) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by total amount:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Item: %s, Qty: %d, Unit: %.2f Tk, Payment: %s, Spot: %s, Total: %.2f Tk\n",
               s[i].saleID, s[i].item, s[i].quantity, s[i].unitPrice, s[i].payment, s[i].spot,
               s[i].quantity * s[i].unitPrice);
    }

    return 0;
}
