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
        {2301, "Carlsen", "Nakamura", "White", 41, "Sicilian"},
        {2302, "Ding", "Nepo", "Draw", 67, "Ruy-Lopez"},
        {2303, "Caruana", "Firouzja", "Black", 33, "Caro-Kann"},
        {2304, "Gukesh", "Erigaisi", "White", 55, "KingsIndian"},
        {2305, "Anand", "Pragg", "Draw", 29, "QueensGambit"},
        {2306, "Abhimanyu", "Niemann", "Black", 48, "FrenchDef"}
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
