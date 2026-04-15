/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Chess Tournament Game Record
 * Operations: linear search by game ID, bubble sort by number of moves
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct chessGame {
    int   gameID;
    char  whitePlayer[20];
    char  blackPlayer[20];
    char  result[10];         /* White / Black / Draw */
    int   totalMoves;
    char  opening[20];        /* e.g. Sicilian, Caro-Kann */
};

typedef struct chessGame GameData;

void Display(GameData g[]);
void Search(GameData g[], int id);
void SortByMoves(GameData g[]);

int main(void)
{
    GameData games[SIZE] = {
        {2301, "Carlsen",   "Nakamura",  "White", 41, "Sicilian"   },
        {2302, "Ding",      "Nepo",      "Draw",  67, "Ruy-Lopez"  },
        {2303, "Caruana",   "Firouzja",  "Black", 33, "Caro-Kann"  },
        {2304, "Gukesh",    "Erigaisi",  "White", 55, "KingsIndian"},
        {2305, "Anand",     "Pragg",     "Draw",  29, "QueensGambit"},
        {2306, "Abhimanyu", "Niemann",   "Black", 48, "FrenchDef"  }
    };

    int id;

    printf("===== Chess games (original) =====\n");
    Display(games);

    printf("\nEnter a game ID to search: ");
    scanf("%d", &id);
    Search(games, id);

    SortByMoves(games);

    printf("\n===== Chess games (sorted by move count) =====\n");
    Display(games);

    return 0;
}

void Display(GameData g[])
{
    int i;
    printf("%-6s %-14s %-14s %-8s %-7s %-14s\n",
           "ID", "White", "Black", "Result", "Moves", "Opening");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-14s %-14s %-8s %-7d %-14s\n",
               g[i].gameID, g[i].whitePlayer, g[i].blackPlayer,
               g[i].result, g[i].totalMoves, g[i].opening);
    }
}

void Search(GameData g[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (g[i].gameID == id) {
            printf("\nGame found:\n");
            printf("  Game ID : %d\n", g[i].gameID);
            printf("  White   : %s\n", g[i].whitePlayer);
            printf("  Black   : %s\n", g[i].blackPlayer);
            printf("  Result  : %s\n", g[i].result);
            printf("  Moves   : %d\n", g[i].totalMoves);
            printf("  Opening : %s\n", g[i].opening);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo chess game with ID %d.\n", id);
    }
}

void SortByMoves(GameData g[])
{
    int i, j;
    GameData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (g[j].totalMoves > g[j + 1].totalMoves) {
                temp     = g[j];
                g[j]     = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }
}
