#include <stdio.h>
#include <string.h>

struct parcel {
    int id;
    char city[30];
    float weight;
    float cost;
    char status[15];
};

int main() {
    struct parcel p[6] = {
        {3301, "Gazipur", 1.8, 140, "Shipped"},
        {3302, "Comilla", 4.2, 225.5, "Delivered"},
        {3303, "Mymensingh", 2.1, 110, "Pending"},
        {3304, "Bogura", 3.0, 185, "Delivered"},
        {3305, "Jessore", 5.5, 290, "Pending"},
        {3306, "Narayanganj", 0.7, 65, "Shipped"}
    };

    int i, j, key, found = 0;
    struct parcel temp;

    printf("All Parcels:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, City: %s, Weight: %.2f kg, Cost: %.2f Tk, Status: %s\n",
               p[i].id, p[i].city, p[i].weight, p[i].cost, p[i].status);
    }

    printf("\nEnter parcel ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (p[i].id == key) {
            printf("Found: %d, %s, %.2f kg, %.2f Tk, %s\n",
                   p[i].id, p[i].city, p[i].weight, p[i].cost, p[i].status);
            found = 1;
        }
    }
    if (found == 0)
        printf("Parcel not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (p[j].cost > p[j + 1].cost) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by cost:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, City: %s, Weight: %.2f kg, Cost: %.2f Tk, Status: %s\n",
               p[i].id, p[i].city, p[i].weight, p[i].cost, p[i].status);
    }

    return 0;
}
