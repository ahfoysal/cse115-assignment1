/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Plant Nursery Stock
 * Operations: linear search by plant ID, bubble sort by price per pot
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct plantStock {
    int   plantID;
    char  species[20];
    int   ageMonths;
    float pricePerPot;   /* taka */
    int   stockCount;
    char  careLevel[10]; /* Easy / Medium / Hard */
};

typedef struct plantStock PlantData;

void Display(PlantData p[]);
void Search(PlantData p[], int id);
void SortByPrice(PlantData p[]);

int main(void)
{
    PlantData stock[SIZE] = {
        {1401, "MoneyPlant",    6,  120.00, 45, "Easy"  },
        {1402, "Bonsai",       36, 2500.00,  8, "Hard"  },
        {1403, "AloeVera",      4,   90.00, 60, "Easy"  },
        {1404, "Rose",         10,  220.00, 25, "Medium"},
        {1405, "SnakePlant",   18,  380.00, 18, "Easy"  },
        {1406, "Orchid",       12,  650.00, 12, "Hard"  }
    };

    int id;

    printf("===== Nursery stock (original) =====\n");
    Display(stock);

    printf("\nEnter a plant ID to search: ");
    scanf("%d", &id);
    Search(stock, id);

    SortByPrice(stock);

    printf("\n===== Nursery stock (sorted by price) =====\n");
    Display(stock);

    return 0;
}

void Display(PlantData p[])
{
    int i;
    printf("%-6s %-14s %-10s %-10s %-8s %-10s\n",
           "ID", "Species", "Age(mon)", "Price(Tk)", "Stock", "Care");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-14s %-10d %-10.2f %-8d %-10s\n",
               p[i].plantID, p[i].species, p[i].ageMonths,
               p[i].pricePerPot, p[i].stockCount, p[i].careLevel);
    }
}

void Search(PlantData p[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (p[i].plantID == id) {
            printf("\nPlant found:\n");
            printf("  Plant ID : %d\n",        p[i].plantID);
            printf("  Species  : %s\n",        p[i].species);
            printf("  Age      : %d months\n", p[i].ageMonths);
            printf("  Price    : %.2f Tk\n",   p[i].pricePerPot);
            printf("  Stock    : %d pots\n",   p[i].stockCount);
            printf("  Care     : %s\n",        p[i].careLevel);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo plant with ID %d.\n", id);
    }
}

void SortByPrice(PlantData p[])
{
    int i, j;
    PlantData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (p[j].pricePerPot > p[j + 1].pricePerPot) {
                temp     = p[j];
                p[j]     = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
