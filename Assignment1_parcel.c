/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Courier Parcel Tracking
 * Operations: linear search by tracking ID, bubble sort by cost
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct parcel {
    int   trackingID;
    char  destination[30];
    float weight;      /* kilograms */
    float cost;        /* taka      */
    char  status[15];  /* Pending / Shipped / Delivered */
};

typedef struct parcel ParcelData;

void Display(ParcelData p[]);
void Search(ParcelData p[], int id);
void SortByCost(ParcelData p[]);

int main(void)
{
    ParcelData parcels[SIZE] = {
        {3301, "Gazipur",     1.8, 140.00, "Shipped"  },
        {3302, "Comilla",     4.2, 225.50, "Delivered"},
        {3303, "Mymensingh",  2.1, 110.00, "Pending"  },
        {3304, "Bogura",      3.0, 185.00, "Delivered"},
        {3305, "Jessore",     5.5, 290.00, "Pending"  },
        {3306, "Narayanganj", 0.7,  65.00, "Shipped"  }
    };

    int searchID;

    printf("===== Parcel list (original) =====\n");
    Display(parcels);

    printf("\nEnter a tracking ID to search: ");
    scanf("%d", &searchID);
    Search(parcels, searchID);

    SortByCost(parcels);

    printf("\n===== Parcel list (sorted by cost) =====\n");
    Display(parcels);

    return 0;
}

void Display(ParcelData p[])
{
    int i;
    printf("%-8s %-12s %-8s %-10s %-10s\n",
           "ID", "Destination", "Wt(kg)", "Cost(Tk)", "Status");
    for (i = 0; i < SIZE; i++) {
        printf("%-8d %-12s %-8.2f %-10.2f %-10s\n",
               p[i].trackingID, p[i].destination,
               p[i].weight, p[i].cost, p[i].status);
    }
}

void Search(ParcelData p[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (p[i].trackingID == id) {
            printf("\nParcel found:\n");
            printf("  ID          : %d\n",      p[i].trackingID);
            printf("  Destination : %s\n",      p[i].destination);
            printf("  Weight      : %.2f kg\n", p[i].weight);
            printf("  Cost        : %.2f Tk\n", p[i].cost);
            printf("  Status      : %s\n",      p[i].status);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo parcel with ID %d in our records.\n", id);
    }
}

void SortByCost(ParcelData p[])
{
    int i, j;
    ParcelData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (p[j].cost > p[j + 1].cost) {
                temp     = p[j];
                p[j]     = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
