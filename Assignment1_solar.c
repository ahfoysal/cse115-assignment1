#include <stdio.h>
#include <string.h>

struct solar {
    int installID;
    char site[25];
    float capacity;
    float cost;
    int efficiency;
    char panel[15];
};

int main() {
    struct solar s[6] = {
        {5501, "Savar Rooftop", 4.5, 320, 22, "Mono"},
        {5502, "Teknaf Solar Park", 25.0, 1850, 19, "Poly"},
        {5503, "Bogura Warehouse", 10.2, 720.5, 21, "Mono"},
        {5504, "Jhenaidah Farm", 6.8, 480, 18, "Thin-film"},
        {5505, "Rangpur Clinic", 3.2, 245, 20, "Poly"},
        {5506, "Sylhet Resort", 8.1, 610, 23, "Mono"}
    };

    int i, j, key, found = 0;
    struct solar temp;

    printf("All Installations:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Site: %s, Capacity: %.2f kW, Cost: %.2f kTk, Eff: %d%%, Type: %s\n",
               s[i].installID, s[i].site, s[i].capacity, s[i].cost, s[i].efficiency, s[i].panel);
    }

    printf("\nEnter install ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (s[i].installID == key) {
            printf("Found: %d, %s, %.2f kW, %.2f kTk, %d%%, %s\n",
                   s[i].installID, s[i].site, s[i].capacity, s[i].cost, s[i].efficiency, s[i].panel);
            found = 1;
        }
    }
    if (found == 0)
        printf("Installation not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (s[j].cost > s[j + 1].cost) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by cost:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Site: %s, Capacity: %.2f kW, Cost: %.2f kTk, Eff: %d%%, Type: %s\n",
               s[i].installID, s[i].site, s[i].capacity, s[i].cost, s[i].efficiency, s[i].panel);
    }

    return 0;
}
