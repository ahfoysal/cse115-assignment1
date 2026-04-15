/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Movie Screening / Show Records
 * Operations: linear search by show ID, bubble sort by seats booked
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct movieShow {
    int   showID;
    char  movieName[25];
    char  hall[12];
    int   seatsBooked;
    float ticketPrice;
    char  startTime[10];   /* e.g. 07:45PM */
};

typedef struct movieShow ShowData;

void Display(ShowData s[]);
void Search(ShowData s[], int id);
void SortBySeats(ShowData s[]);

int main(void)
{
    ShowData shows[SIZE] = {
        {4401, "Hawa",             "Star-1",  180, 400.00, "06:30PM"},
        {4402, "Poran",            "Blockbuster", 140, 450.00, "09:15PM"},
        {4403, "Monpura",          "Balaka",  95, 250.00, "03:00PM"},
        {4404, "Priyotoma",        "Star-2",  210, 500.00, "07:45PM"},
        {4405, "Interstellar",     "IMAX",    250, 650.00, "10:30PM"},
        {4406, "Dune",             "Star-3",  175, 550.00, "08:00PM"}
    };

    int id;

    printf("===== Movie shows (original) =====\n");
    Display(shows);

    printf("\nEnter a show ID to search: ");
    scanf("%d", &id);
    Search(shows, id);

    SortBySeats(shows);

    printf("\n===== Movie shows (sorted by seats booked) =====\n");
    Display(shows);

    return 0;
}

void Display(ShowData s[])
{
    int i;
    printf("%-6s %-18s %-14s %-6s %-10s %-10s\n",
           "ID", "Movie", "Hall", "Seats", "Price(Tk)", "Time");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-18s %-14s %-6d %-10.2f %-10s\n",
               s[i].showID, s[i].movieName, s[i].hall,
               s[i].seatsBooked, s[i].ticketPrice, s[i].startTime);
    }
}

void Search(ShowData s[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (s[i].showID == id) {
            printf("\nShow found:\n");
            printf("  Show ID    : %d\n",      s[i].showID);
            printf("  Movie      : %s\n",      s[i].movieName);
            printf("  Hall       : %s\n",      s[i].hall);
            printf("  Seats      : %d\n",      s[i].seatsBooked);
            printf("  Price      : %.2f Tk\n", s[i].ticketPrice);
            printf("  Start Time : %s\n",      s[i].startTime);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo show with ID %d.\n", id);
    }
}

void SortBySeats(ShowData s[])
{
    int i, j;
    ShowData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (s[j].seatsBooked > s[j + 1].seatsBooked) {
                temp     = s[j];
                s[j]     = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
