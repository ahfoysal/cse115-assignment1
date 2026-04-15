/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Drone Flight Log
 * Operations: linear search by flight ID, bubble sort by duration
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct droneFlight {
    int   flightID;
    char  droneModel[20];   /* e.g. DJI-Mini-3 */
    float duration;         /* minutes */
    float maxAltitude;      /* meters */
    int   batteryUsed;      /* percent */
};

typedef struct droneFlight FlightData;

void Display(FlightData f[]);
void Search(FlightData f[], int id);
void SortByDuration(FlightData f[]);

int main(void)
{
    FlightData flights[SIZE] = {
        {7001, "DJI-Mini-3",   18.5, 120.0, 65},
        {7002, "Autel-Evo",    22.0, 150.0, 78},
        {7003, "Parrot-Anafi", 10.3,  80.0, 40},
        {7004, "DJI-Air-2S",   26.7, 180.0, 85},
        {7005, "Skydio-2",     14.2, 100.0, 55},
        {7006, "DJI-Mavic-3",  30.1, 200.0, 92}
    };

    int id;

    printf("===== Flight log (original) =====\n");
    Display(flights);

    printf("\nEnter a flight ID to search: ");
    scanf("%d", &id);
    Search(flights, id);

    SortByDuration(flights);

    printf("\n===== Flight log (sorted by duration) =====\n");
    Display(flights);

    return 0;
}

void Display(FlightData f[])
{
    int i;
    printf("%-6s %-14s %-10s %-10s %-8s\n",
           "ID", "Model", "Dur(min)", "Alt(m)", "Batt(%)");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-14s %-10.2f %-10.2f %-8d\n",
               f[i].flightID, f[i].droneModel,
               f[i].duration, f[i].maxAltitude, f[i].batteryUsed);
    }
}

void Search(FlightData f[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (f[i].flightID == id) {
            printf("\nFlight found:\n");
            printf("  Flight ID : %d\n",      f[i].flightID);
            printf("  Model     : %s\n",      f[i].droneModel);
            printf("  Duration  : %.2f min\n", f[i].duration);
            printf("  Altitude  : %.2f m\n",  f[i].maxAltitude);
            printf("  Battery   : %d %%\n",   f[i].batteryUsed);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo flight log with ID %d.\n", id);
    }
}

void SortByDuration(FlightData f[])
{
    int i, j;
    FlightData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (f[j].duration > f[j + 1].duration) {
                temp     = f[j];
                f[j]     = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }
}
