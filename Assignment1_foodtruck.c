/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Food Truck Sales
 * Operations: linear search by sale ID, bubble sort by total amount
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct foodSale {
    int   saleID;
    char  item[20];
    int   quantity;
    float pricePerItem;    /* taka */
    char  payment[10];     /* Cash / bKash / Card */
    char  spot[15];        /* e.g. Dhanmondi-27 */
};

typedef struct foodSale SaleData;

void Display(SaleData s[]);
void Search(SaleData s[], int id);
void SortByTotal(SaleData s[]);

int main(void)
{
    SaleData sales[SIZE] = {
        {101, "Burger",        2, 180.00, "Cash",  "Dhanmondi-27"},
        {102, "Shawarma",      4, 150.00, "bKash", "Banani-11"   },
        {103, "Pasta",         1, 220.00, "Card",  "Gulshan-2"   },
        {104, "Fries",         3,  80.00, "Cash",  "Uttara-4"    },
        {105, "HotDog",        2, 130.00, "bKash", "Mirpur-10"   },
        {106, "ChickenWrap",   5, 170.00, "Card",  "Bashundhara" }
    };

    int id;

    printf("===== Food truck sales (original) =====\n");
    Display(sales);

    printf("\nEnter a sale ID to search: ");
    scanf("%d", &id);
    Search(sales, id);

    SortByTotal(sales);

    printf("\n===== Food truck sales (sorted by total amount) =====\n");
    Display(sales);

    return 0;
}

void Display(SaleData s[])
{
    int i;
    float total;
    printf("%-6s %-14s %-4s %-10s %-10s %-15s %-10s\n",
           "ID", "Item", "Qty", "Unit(Tk)", "Payment", "Spot", "Total");
    for (i = 0; i < SIZE; i++) {
        total = s[i].quantity * s[i].pricePerItem;
        printf("%-6d %-14s %-4d %-10.2f %-10s %-15s %-10.2f\n",
               s[i].saleID, s[i].item, s[i].quantity,
               s[i].pricePerItem, s[i].payment, s[i].spot, total);
    }
}

void Search(SaleData s[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (s[i].saleID == id) {
            printf("\nSale found:\n");
            printf("  Sale ID  : %d\n",      s[i].saleID);
            printf("  Item     : %s\n",      s[i].item);
            printf("  Quantity : %d\n",      s[i].quantity);
            printf("  Unit     : %.2f Tk\n", s[i].pricePerItem);
            printf("  Payment  : %s\n",      s[i].payment);
            printf("  Spot     : %s\n",      s[i].spot);
            printf("  Total    : %.2f Tk\n", s[i].quantity * s[i].pricePerItem);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo sale with ID %d.\n", id);
    }
}

void SortByTotal(SaleData s[])
{
    int i, j;
    SaleData temp;
    float a, b;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            a = s[j].quantity     * s[j].pricePerItem;
            b = s[j + 1].quantity * s[j + 1].pricePerItem;
            if (a > b) {
                temp     = s[j];
                s[j]     = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
