/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Solar Panel Installation Records
 * Operations: linear search by install ID, bubble sort by cost
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct solarInstall {
    int   installID;
    char  siteName[25];
    float capacityKW;      /* kilowatts */
    float cost;            /* in thousand taka */
    int   efficiency;      /* percent */
    char  panelType[15];   /* Mono / Poly / Thin-film */
};

typedef struct solarInstall SolarData;

void Display(SolarData s[]);
void Search(SolarData s[], int id);
void SortByCost(SolarData s[]);

int main(void)
{
    SolarData sites[SIZE] = {
        {5501, "Savar Rooftop",      4.5, 320.00, 22, "Mono"     },
        {5502, "Teknaf Solar Park", 25.0, 1850.00, 19, "Poly"    },
        {5503, "Bogura Warehouse",  10.2, 720.50, 21, "Mono"     },
        {5504, "Jhenaidah Farm",     6.8, 480.00, 18, "Thin-film"},
        {5505, "Rangpur Clinic",     3.2, 245.00, 20, "Poly"     },
        {5506, "Sylhet Resort",      8.1, 610.00, 23, "Mono"     }
    };

    int id;

    printf("===== Solar sites (original) =====\n");
    Display(sites);

    printf("\nEnter an install ID to search: ");
    scanf("%d", &id);
    Search(sites, id);

    SortByCost(sites);

    printf("\n===== Solar sites (sorted by cost) =====\n");
    Display(sites);

    return 0;
}

void Display(SolarData s[])
{
    int i;
    printf("%-6s %-20s %-10s %-12s %-8s %-12s\n",
           "ID", "Site", "kW", "Cost(kTk)", "Eff(%)", "Type");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-20s %-10.2f %-12.2f %-8d %-12s\n",
               s[i].installID, s[i].siteName, s[i].capacityKW,
               s[i].cost, s[i].efficiency, s[i].panelType);
    }
}

void Search(SolarData s[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (s[i].installID == id) {
            printf("\nInstallation found:\n");
            printf("  Install ID : %d\n",       s[i].installID);
            printf("  Site       : %s\n",       s[i].siteName);
            printf("  Capacity   : %.2f kW\n",  s[i].capacityKW);
            printf("  Cost       : %.2f kTk\n", s[i].cost);
            printf("  Efficiency : %d %%\n",    s[i].efficiency);
            printf("  Panel Type : %s\n",       s[i].panelType);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo installation with ID %d.\n", id);
    }
}

void SortByCost(SolarData s[])
{
    int i, j;
    SolarData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (s[j].cost > s[j + 1].cost) {
                temp     = s[j];
                s[j]     = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
