#include <stdio.h>
#include <string.h>

struct busTicket {
    int ticketNo;
    char route[30];
    char busName[20];
    int seatNo;
    float fare;
};

int main() {
    struct busTicket t[6] = {
        {812, "Dhaka-Benapole", "Desh", 18, 1050},
        {813, "Dhaka-Kushtia", "SR", 9, 780},
        {814, "Dhaka-Saidpur", "Hanif", 25, 1250},
        {815, "Dhaka-Teknaf", "Royal", 11, 1950},
        {816, "Dhaka-Jamalpur", "Shyamoli", 17, 620},
        {817, "Dhaka-Noakhali", "Econo", 3, 580}
    };

    int i, j, key, found = 0;
    struct busTicket temp;

    printf("All Tickets:\n");
    for (i = 0; i < 6; i++) {
        printf("No: %d, Route: %s, Bus: %s, Seat: %d, Fare: %.2f Tk\n",
               t[i].ticketNo, t[i].route, t[i].busName, t[i].seatNo, t[i].fare);
    }

    printf("\nEnter ticket no to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (t[i].ticketNo == key) {
            printf("Found: %d, %s, %s, Seat %d, %.2f Tk\n",
                   t[i].ticketNo, t[i].route, t[i].busName, t[i].seatNo, t[i].fare);
            found = 1;
        }
    }
    if (found == 0)
        printf("Ticket not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (t[j].fare > t[j + 1].fare) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by fare:\n");
    for (i = 0; i < 6; i++) {
        printf("No: %d, Route: %s, Bus: %s, Seat: %d, Fare: %.2f Tk\n",
               t[i].ticketNo, t[i].route, t[i].busName, t[i].seatNo, t[i].fare);
    }

    return 0;
}
