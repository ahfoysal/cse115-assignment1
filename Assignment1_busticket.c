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
        {921, "Dhaka-Chuadanga", "Desh", 14, 890},
        {922, "Dhaka-Satkhira", "SR", 7, 1100},
        {923, "Dhaka-Dinajpur", "Hanif", 21, 1350},
        {924, "Dhaka-Bandarban", "Royal", 8, 1720},
        {925, "Dhaka-Magura", "Shyamoli", 19, 740},
        {926, "Dhaka-Lakshmipur", "Econo", 5, 540}
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
