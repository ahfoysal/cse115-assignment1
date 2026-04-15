#include <stdio.h>
#include <string.h>

struct show {
    int showID;
    char movie[25];
    char hall[15];
    int seats;
    float price;
    char time[10];
};

int main() {
    struct show s[6] = {
        {4511, "Surongo", "Star-4", 165, 420, "05:45PM"},
        {4512, "Mujib", "Blockbuster", 125, 380, "08:30PM"},
        {4513, "Aynabaji", "Balaka", 88, 230, "02:15PM"},
        {4514, "Debi", "Star-1", 195, 470, "06:50PM"},
        {4515, "Oppenheimer", "IMAX", 235, 700, "09:45PM"},
        {4516, "Oppenheimer", "Star-2", 160, 520, "07:20PM"}
    };

    int i, j, key, found = 0;
    struct show temp;

    printf("All Shows:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Movie: %s, Hall: %s, Seats: %d, Price: %.2f Tk, Time: %s\n",
               s[i].showID, s[i].movie, s[i].hall, s[i].seats, s[i].price, s[i].time);
    }

    printf("\nEnter show ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (s[i].showID == key) {
            printf("Found: %d, %s, %s, %d seats, %.2f Tk, %s\n",
                   s[i].showID, s[i].movie, s[i].hall, s[i].seats, s[i].price, s[i].time);
            found = 1;
        }
    }
    if (found == 0)
        printf("Show not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (s[j].seats > s[j + 1].seats) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by seats booked:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Movie: %s, Hall: %s, Seats: %d, Price: %.2f Tk, Time: %s\n",
               s[i].showID, s[i].movie, s[i].hall, s[i].seats, s[i].price, s[i].time);
    }

    return 0;
}
