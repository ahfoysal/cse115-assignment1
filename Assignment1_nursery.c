#include <stdio.h>
#include <string.h>

struct plant {
    int plantID;
    char species[20];
    int age;
    float price;
    int stock;
    char care[10];
};

int main() {
    struct plant p[6] = {
        {1401, "MoneyPlant", 6, 120, 45, "Easy"},
        {1402, "Bonsai", 36, 2500, 8, "Hard"},
        {1403, "AloeVera", 4, 90, 60, "Easy"},
        {1404, "Rose", 10, 220, 25, "Medium"},
        {1405, "SnakePlant", 18, 380, 18, "Easy"},
        {1406, "Orchid", 12, 650, 12, "Hard"}
    };

    int i, j, key, found = 0;
    struct plant temp;

    printf("All Plants:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Species: %s, Age: %d months, Price: %.2f Tk, Stock: %d, Care: %s\n",
               p[i].plantID, p[i].species, p[i].age, p[i].price, p[i].stock, p[i].care);
    }

    printf("\nEnter plant ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (p[i].plantID == key) {
            printf("Found: %d, %s, %d months, %.2f Tk, Stock %d, %s\n",
                   p[i].plantID, p[i].species, p[i].age, p[i].price, p[i].stock, p[i].care);
            found = 1;
        }
    }
    if (found == 0)
        printf("Plant not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (p[j].price > p[j + 1].price) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by price:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Species: %s, Age: %d months, Price: %.2f Tk, Stock: %d, Care: %s\n",
               p[i].plantID, p[i].species, p[i].age, p[i].price, p[i].stock, p[i].care);
    }

    return 0;
}
