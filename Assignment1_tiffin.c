/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Tiffin Box Lunch Delivery Orders
 * Operations: linear search by order ID, bubble sort by price
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct tiffinOrder {
    int   orderID;
    char  menuName[30];     /* e.g. Chicken Biryani Box */
    int   quantity;
    float price;            /* taka (total) */
    char  deliveryArea[20]; /* e.g. Bashundhara */
};

typedef struct tiffinOrder TiffinData;

void Display(TiffinData o[]);
void Search(TiffinData o[], int id);
void SortByPrice(TiffinData o[]);

int main(void)
{
    TiffinData orders[SIZE] = {
        {9001, "Chicken Biryani Box", 2, 360.00, "Bashundhara"},
        {9002, "Beef Khichuri",       1, 180.00, "Dhanmondi"  },
        {9003, "Veg Thali",           3, 330.00, "Uttara"     },
        {9004, "Fish Curry Meal",     1, 220.00, "Mirpur"     },
        {9005, "Egg Fried Rice",      2, 260.00, "Banani"     },
        {9006, "Mutton Tehari",       1, 300.00, "Mohammadpur"}
    };

    int id;

    printf("===== Tiffin orders (original) =====\n");
    Display(orders);

    printf("\nEnter an order ID to search: ");
    scanf("%d", &id);
    Search(orders, id);

    SortByPrice(orders);

    printf("\n===== Tiffin orders (sorted by price) =====\n");
    Display(orders);

    return 0;
}

void Display(TiffinData o[])
{
    int i;
    printf("%-6s %-22s %-4s %-10s %-14s\n",
           "ID", "Menu", "Qty", "Price(Tk)", "Area");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-22s %-4d %-10.2f %-14s\n",
               o[i].orderID, o[i].menuName, o[i].quantity,
               o[i].price, o[i].deliveryArea);
    }
}

void Search(TiffinData o[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (o[i].orderID == id) {
            printf("\nOrder found:\n");
            printf("  Order ID : %d\n",      o[i].orderID);
            printf("  Menu     : %s\n",      o[i].menuName);
            printf("  Quantity : %d\n",      o[i].quantity);
            printf("  Price    : %.2f Tk\n", o[i].price);
            printf("  Area     : %s\n",      o[i].deliveryArea);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo order found with ID %d.\n", id);
    }
}

void SortByPrice(TiffinData o[])
{
    int i, j;
    TiffinData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (o[j].price > o[j + 1].price) {
                temp     = o[j];
                o[j]     = o[j + 1];
                o[j + 1] = temp;
            }
        }
    }
}
