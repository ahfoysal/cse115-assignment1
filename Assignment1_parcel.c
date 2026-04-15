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
        {3307, "Tangail", 2.3, 155, "Shipped"},
        {3308, "Feni", 3.9, 210, "Delivered"},
        {3309, "Pabna", 1.7, 98, "Pending"},
        {3310, "Naogaon", 4.1, 232, "Delivered"},
        {3311, "Brahmanbaria", 6.2, 315, "Pending"},
        {3312, "Sirajganj", 0.8, 72, "Shipped"}
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
