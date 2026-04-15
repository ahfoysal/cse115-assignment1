/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Taxi / CNG Ride Log
 * Operations: linear search by ride ID, bubble sort by fare
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct rideLog {
    int   rideID;
    char  fromArea[15];
    char  toArea[15];
    char  vehicle[10];    /* CNG / Taxi / Uber / Pathao */
    float distanceKm;
    float fare;           /* taka */
};

typedef struct rideLog RideData;

void Display(RideData r[]);
void Search(RideData r[], int id);
void SortByFare(RideData r[]);

int main(void)
{
    RideData rides[SIZE] = {
        {9911, "Mohakhali",   "Gulshan-1",   "CNG",     4.2, 220.00},
        {9912, "Uttara",      "Banani",      "Uber",    9.0, 410.00},
        {9913, "Mirpur-10",   "Dhanmondi",   "Pathao",  7.5, 280.00},
        {9914, "Farmgate",    "Motijheel",   "Taxi",    6.1, 340.00},
        {9915, "Shyamoli",    "Bashundhara", "Uber",   11.3, 520.00},
        {9916, "Airport",     "Agrabad(Ctg)","Taxi",   12.0, 650.00}
    };

    int id;

    printf("===== Ride log (original) =====\n");
    Display(rides);

    printf("\nEnter a ride ID to search: ");
    scanf("%d", &id);
    Search(rides, id);

    SortByFare(rides);

    printf("\n===== Ride log (sorted by fare) =====\n");
    Display(rides);

    return 0;
}

void Display(RideData r[])
{
    int i;
    printf("%-6s %-12s %-14s %-10s %-8s %-10s\n",
           "ID", "From", "To", "Vehicle", "Km", "Fare(Tk)");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-12s %-14s %-10s %-8.2f %-10.2f\n",
               r[i].rideID, r[i].fromArea, r[i].toArea,
               r[i].vehicle, r[i].distanceKm, r[i].fare);
    }
}

void Search(RideData r[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (r[i].rideID == id) {
            printf("\nRide found:\n");
            printf("  Ride ID  : %d\n",       r[i].rideID);
            printf("  From     : %s\n",       r[i].fromArea);
            printf("  To       : %s\n",       r[i].toArea);
            printf("  Vehicle  : %s\n",       r[i].vehicle);
            printf("  Distance : %.2f km\n",  r[i].distanceKm);
            printf("  Fare     : %.2f Tk\n",  r[i].fare);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo ride with ID %d.\n", id);
    }
}

void SortByFare(RideData r[])
{
    int i, j;
    RideData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (r[j].fare > r[j + 1].fare) {
                temp     = r[j];
                r[j]     = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }
}
