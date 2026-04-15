#include <stdio.h>
#include <string.h>

struct match {
    int matchID;
    char team1[15];
    char team2[15];
    char winner[15];
    int margin;
    char venue[20];
};

int main() {
    struct match m[6] = {
        {6101, "Bangladesh", "India", "India", 35, "Mirpur"},
        {6102, "Pakistan", "Srilanka", "Pakistan", 6, "Lahore"},
        {6103, "Australia", "England", "Australia", 78, "Sydney"},
        {6104, "Bangladesh", "Afghan", "Bangladesh", 22, "Chattogram"},
        {6105, "Newzealand", "Westind", "Newzealand", 14, "Auckland"},
        {6106, "India", "Srilanka", "India", 55, "Colombo"}
    };

    int i, j, key, found = 0;
    struct match temp;

    printf("All Matches:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, %s vs %s, Winner: %s, Margin: %d, Venue: %s\n",
               m[i].matchID, m[i].team1, m[i].team2, m[i].winner, m[i].margin, m[i].venue);
    }

    printf("\nEnter match ID to search: ");
    scanf("%d", &key);
    for (i = 0; i < 6; i++) {
        if (m[i].matchID == key) {
            printf("Found: %d, %s vs %s, Winner: %s, Margin: %d, Venue: %s\n",
                   m[i].matchID, m[i].team1, m[i].team2, m[i].winner, m[i].margin, m[i].venue);
            found = 1;
        }
    }
    if (found == 0)
        printf("Match not found.\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5 - i; j++) {
            if (m[j].margin > m[j + 1].margin) {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting by margin:\n");
    for (i = 0; i < 6; i++) {
        printf("ID: %d, %s vs %s, Winner: %s, Margin: %d, Venue: %s\n",
               m[i].matchID, m[i].team1, m[i].team2, m[i].winner, m[i].margin, m[i].venue);
    }

    return 0;
}
