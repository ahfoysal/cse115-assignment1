/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Bakery Cake Order
 * Operations: linear search by order ID, bubble sort by price
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct cakeOrder {
    int   orderID;
    char  flavor[20];
    float sizeKg;
    float price;
    char  decoration[25];
    char  pickupTime[10];   /* e.g. 05:30PM */
};

typedef struct cakeOrder CakeData;

void Display(CakeData c[]);
void Search(CakeData c[], int id);
void SortByPrice(CakeData c[]);

int main(void)
{
    CakeData cakes[SIZE] = {
        {7701, "Chocolate",   1.0,  850.00, "Rose topping",     "05:00PM"},
        {7702, "Vanilla",     0.5,  450.00, "Happy Birthday",   "11:00AM"},
        {7703, "RedVelvet",   2.0, 1800.00, "Gold foil",        "07:30PM"},
        {7704, "Blackforest", 1.5, 1250.00, "Cherry cluster",   "02:45PM"},
        {7705, "Strawberry",  1.0,  950.00, "Fruit slices",     "06:15PM"},
        {7706, "Cheesecake",  0.8,  780.00, "Caramel drizzle",  "04:00PM"}
    };

    int id;

    printf("===== Cake orders (original) =====\n");
    Display(cakes);

    printf("\nEnter an order ID to search: ");
    scanf("%d", &id);
    Search(cakes, id);

    SortByPrice(cakes);

    printf("\n===== Cake orders (sorted by price) =====\n");
    Display(cakes);

    return 0;
}

void Display(CakeData c[])
{
    int i;
    printf("%-6s %-14s %-8s %-10s %-20s %-10s\n",
           "ID", "Flavor", "Size(kg)", "Price(Tk)", "Decoration", "Pickup");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-14s %-8.2f %-10.2f %-20s %-10s\n",
               c[i].orderID, c[i].flavor, c[i].sizeKg,
               c[i].price, c[i].decoration, c[i].pickupTime);
    }
}

void Search(CakeData c[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (c[i].orderID == id) {
            printf("\nOrder found:\n");
            printf("  Order ID   : %d\n",      c[i].orderID);
            printf("  Flavor     : %s\n",      c[i].flavor);
            printf("  Size       : %.2f kg\n", c[i].sizeKg);
            printf("  Price      : %.2f Tk\n", c[i].price);
            printf("  Decoration : %s\n",      c[i].decoration);
            printf("  Pickup     : %s\n",      c[i].pickupTime);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo cake order with ID %d.\n", id);
    }
}

void SortByPrice(CakeData c[])
{
    int i, j;
    CakeData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (c[j].price > c[j + 1].price) {
                temp     = c[j];
                c[j]     = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}
