#include <stdio.h>
#include <string.h>

struct drone {
    int flightID;
    char model[20];
    float duration;
    float altitude;
    int battery;
};

int main() {
    struct drone f[6] = {
        {2210, "DJI-Mini-4", 16.4, 115, 58},
        {2211, "Autel-Nano", 24.8, 165, 82},
        {2212, "Hubsan-Zino", 12.7, 90, 47},
        {2213, "DJI-Phantom", 28.3, 195, 88},
        {2214, "Skydio-X2", 19.6, 135, 70},
        {2215, "DJI-Mavic-Pro", 33.5, 220, 95}
    };

    int i, j, key, found = 0;
    struct drone temp;

    printf("All Flights:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Model: %s, Duration: %.2f min, Altitude: %.2f m, Battery: %d%%\n",
               f[i].flightID, f[i].model, f[i].duration, f[i].altitude, f[i].battery);
    }

    printf("\nEnter flight ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (f[i].flightID == key) {
            printf("Found: %d, %s, %.2f min, %.2f m, %d%%\n",
                   f[i].flightID, f[i].model, f[i].duration, f[i].altitude, f[i].battery);
            found = 1;
        }
    }
    if (found == 0)
        printf("Flight not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (f[j].duration > f[j + 1].duration) {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by duration:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Model: %s, Duration: %.2f min, Altitude: %.2f m, Battery: %d%%\n",
               f[i].flightID, f[i].model, f[i].duration, f[i].altitude, f[i].battery);
    }

    return 0;
}
