#include <stdio.h>
#include <string.h>

struct chess {
    int gameID;
    char white[20];
    char black[20];
    char result[10];
    int moves;
    char opening[20];
};

int main() {
    struct chess g[6] = {
        {2401, "Carlsen", "Duda", "White", 38, "Italian"},
        {2402, "Nakamura", "So", "Draw", 72, "Berlin"},
        {2403, "Firouzja", "Aronian", "Black", 44, "Slav"},
        {2404, "Pragg", "Nepo", "White", 51, "EnglishOp"},
        {2405, "Caruana", "Ding", "Draw", 35, "GrunfeldDef"},
        {2406, "Niemann", "Gukesh", "Black", 59, "ScotchGame"}
    };

    int i, j, key, found = 0;
    struct chess temp;

    printf("All Games:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, %s vs %s, Result: %s, Moves: %d, Opening: %s\n",
               g[i].gameID, g[i].white, g[i].black, g[i].result, g[i].moves, g[i].opening);
    }

    printf("\nEnter game ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (g[i].gameID == key) {
            printf("Found: %d, %s vs %s, Result: %s, Moves: %d, Opening: %s\n",
                   g[i].gameID, g[i].white, g[i].black, g[i].result, g[i].moves, g[i].opening);
            found = 1;
        }
    }
    if (found == 0)
        printf("Game not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (g[j].moves > g[j + 1].moves) {
                temp = g[j];
                g[j] = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by moves:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, %s vs %s, Result: %s, Moves: %d, Opening: %s\n",
               g[i].gameID, g[i].white, g[i].black, g[i].result, g[i].moves, g[i].opening);
    }

    return 0;
}
