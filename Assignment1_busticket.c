/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Intercity Bus Ticket Booking
 * Operations: linear search by ticket number, bubble sort by fare
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct busTicket {
    int   ticketNo;
    char  route[30];      /* e.g. Dhaka-Cox's Bazar */
    char  busName[20];    /* e.g. Hanif, Green Line */
    int   seatNo;
    float fare;           /* taka */
};

typedef struct busTicket TicketData;

void Display(TicketData t[]);
void Search(TicketData t[], int no);
void SortByFare(TicketData t[]);

int main(void)
{
    TicketData tickets[SIZE] = {
        {501, "Dhaka-Coxs Bazar", "Hanif",     12, 1800.00},
        {502, "Dhaka-Sylhet",     "Green Line", 4, 1200.00},
        {503, "Dhaka-Rajshahi",   "Shyamoli",  22,  950.00},
        {504, "Dhaka-Khulna",     "Eagle",      7,  850.00},
        {505, "Dhaka-Barishal",   "Sakura",    15,  700.00},
        {506, "Dhaka-Rangpur",    "Nabil",     30, 1100.00}
    };

    int no;

    printf("===== Ticket list (original) =====\n");
    Display(tickets);

    printf("\nEnter a ticket number to search: ");
    scanf("%d", &no);
    Search(tickets, no);

    SortByFare(tickets);

    printf("\n===== Ticket list (sorted by fare) =====\n");
    Display(tickets);

    return 0;
}

void Display(TicketData t[])
{
    int i;
    printf("%-6s %-20s %-12s %-6s %-10s\n",
           "No", "Route", "Bus", "Seat", "Fare(Tk)");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-20s %-12s %-6d %-10.2f\n",
               t[i].ticketNo, t[i].route, t[i].busName,
               t[i].seatNo, t[i].fare);
    }
}

void Search(TicketData t[], int no)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (t[i].ticketNo == no) {
            printf("\nTicket found:\n");
            printf("  Ticket No : %d\n",      t[i].ticketNo);
            printf("  Route     : %s\n",      t[i].route);
            printf("  Bus       : %s\n",      t[i].busName);
            printf("  Seat      : %d\n",      t[i].seatNo);
            printf("  Fare      : %.2f Tk\n", t[i].fare);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo ticket found with number %d.\n", no);
    }
}

void SortByFare(TicketData t[])
{
    int i, j;
    TicketData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (t[j].fare > t[j + 1].fare) {
                temp     = t[j];
                t[j]     = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}
