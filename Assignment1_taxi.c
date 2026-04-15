#include <stdio.h>
#include <string.h>

struct ride {
    int rideID;
    char fromArea[15];
    char toArea[15];
    char vehicle[10];
    float distance;
    float fare;
};

int main() {
    struct ride r[6] = {
        {8821, "Rampura", "Uttara", "CNG", 10.5, 420},
        {8822, "Mohammadpur", "Motijheel", "Uber", 8.2, 380},
        {8823, "Badda", "Farmgate", "Pathao", 6.8, 250},
        {8824, "Kallyanpur", "Gulshan-2", "Taxi", 7.4, 360},
        {8825, "Khilgaon", "Bashundhara", "Uber", 9.6, 460},
        {8826, "Malibagh", "Airport", "Taxi", 13.5, 710}
    };

    int i, j, key, found = 0;
    struct ride temp;

    printf("All Rides:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, From: %s, To: %s, Vehicle: %s, Distance: %.2f km, Fare: %.2f Tk\n",
               r[i].rideID, r[i].fromArea, r[i].toArea, r[i].vehicle, r[i].distance, r[i].fare);
    }

    printf("\nEnter ride ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (r[i].rideID == key) {
            printf("Found: %d, %s to %s, %s, %.2f km, %.2f Tk\n",
                   r[i].rideID, r[i].fromArea, r[i].toArea, r[i].vehicle, r[i].distance, r[i].fare);
            found = 1;
        }
    }
    if (found == 0)
        printf("Ride not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (r[j].fare > r[j + 1].fare) {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by fare:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, From: %s, To: %s, Vehicle: %s, Distance: %.2f km, Fare: %.2f Tk\n",
               r[i].rideID, r[i].fromArea, r[i].toArea, r[i].vehicle, r[i].distance, r[i].fare);
    }

    return 0;
}
