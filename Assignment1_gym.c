#include <stdio.h>
#include <string.h>

struct gym {
    int sessionID;
    char exercise[20];
    int duration;
    float calories;
    char level[10];
    char date[12];
};

int main() {
    struct gym g[6] = {
        {3111, "Rowing", 35, 310.5, "Medium", "02-04-2026"},
        {3112, "BenchPress", 40, 295, "Hard", "03-04-2026"},
        {3113, "Elliptical", 55, 475, "Medium", "04-04-2026"},
        {3114, "Pilates", 45, 210, "Easy", "06-04-2026"},
        {3115, "CrossFit", 30, 410, "Hard", "09-04-2026"},
        {3116, "Boxing", 45, 580, "Hard", "11-04-2026"}
    };

    int i, j, key, found = 0;
    struct gym temp;

    printf("All Sessions:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Exercise: %s, Duration: %d min, Calories: %.2f, Level: %s, Date: %s\n",
               g[i].sessionID, g[i].exercise, g[i].duration, g[i].calories, g[i].level, g[i].date);
    }

    printf("\nEnter session ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (g[i].sessionID == key) {
            printf("Found: %d, %s, %d min, %.2f kcal, %s, %s\n",
                   g[i].sessionID, g[i].exercise, g[i].duration, g[i].calories, g[i].level, g[i].date);
            found = 1;
        }
    }
    if (found == 0)
        printf("Session not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (g[j].calories > g[j + 1].calories) {
                temp = g[j];
                g[j] = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by calories:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, Exercise: %s, Duration: %d min, Calories: %.2f, Level: %s, Date: %s\n",
               g[i].sessionID, g[i].exercise, g[i].duration, g[i].calories, g[i].level, g[i].date);
    }

    return 0;
}
