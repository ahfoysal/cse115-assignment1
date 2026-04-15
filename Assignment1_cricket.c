/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Cricket Match Record
 * Operations: linear search by match ID, bubble sort by winning margin
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct cricketMatch {
    int   matchID;
    char  team1[15];
    char  team2[15];
    char  winner[15];
    int   margin;         /* runs or wickets, simplified as a number */
    char  venue[20];
};

typedef struct cricketMatch MatchData;

void Display(MatchData m[]);
void Search(MatchData m[], int id);
void SortByMargin(MatchData m[]);

int main(void)
{
    MatchData matches[SIZE] = {
        {6101, "Bangladesh", "India",    "India",       35, "Mirpur"      },
        {6102, "Pakistan",   "Srilanka", "Pakistan",     6, "Lahore"      },
        {6103, "Australia",  "England",  "Australia",   78, "Sydney"      },
        {6104, "Bangladesh", "Afghan",   "Bangladesh",  22, "Chattogram"  },
        {6105, "Newzealand", "Westind",  "Newzealand",  14, "Auckland"    },
        {6106, "India",      "Srilanka", "India",       55, "Colombo"     }
    };

    int id;

    printf("===== Match records (original) =====\n");
    Display(matches);

    printf("\nEnter a match ID to search: ");
    scanf("%d", &id);
    Search(matches, id);

    SortByMargin(matches);

    printf("\n===== Match records (sorted by margin) =====\n");
    Display(matches);

    return 0;
}

void Display(MatchData m[])
{
    int i;
    printf("%-6s %-12s %-12s %-12s %-8s %-14s\n",
           "ID", "Team1", "Team2", "Winner", "Margin", "Venue");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-12s %-12s %-12s %-8d %-14s\n",
               m[i].matchID, m[i].team1, m[i].team2,
               m[i].winner, m[i].margin, m[i].venue);
    }
}

void Search(MatchData m[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (m[i].matchID == id) {
            printf("\nMatch found:\n");
            printf("  Match ID : %d\n", m[i].matchID);
            printf("  Team 1   : %s\n", m[i].team1);
            printf("  Team 2   : %s\n", m[i].team2);
            printf("  Winner   : %s\n", m[i].winner);
            printf("  Margin   : %d\n", m[i].margin);
            printf("  Venue    : %s\n", m[i].venue);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo match found with ID %d.\n", id);
    }
}

void SortByMargin(MatchData m[])
{
    int i, j;
    MatchData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (m[j].margin > m[j + 1].margin) {
                temp     = m[j];
                m[j]     = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
}
