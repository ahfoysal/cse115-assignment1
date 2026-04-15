/*
 * CSE-115 : Programming Language I
 * Assignment 1 - User Defined Data Type (Structure)
 * Topic    : Gym Workout Session Log
 * Operations: linear search by session ID, bubble sort by calories burned
 */

#include <stdio.h>
#include <string.h>

#define SIZE 6

struct gymSession {
    int   sessionID;
    char  exercise[20];
    int   durationMin;
    float caloriesBurned;
    char  difficulty[10];   /* Easy / Medium / Hard */
    char  workoutDate[12];  /* DD-MM-YYYY */
};

typedef struct gymSession SessionData;

void Display(SessionData s[]);
void Search(SessionData s[], int id);
void SortByCalories(SessionData s[]);

int main(void)
{
    SessionData sessions[SIZE] = {
        {3001, "Treadmill",   45, 420.5, "Medium", "05-04-2026"},
        {3002, "DeadLift",    30, 280.0, "Hard",   "06-04-2026"},
        {3003, "Cycling",     60, 550.0, "Medium", "07-04-2026"},
        {3004, "Yoga",        40, 180.0, "Easy",   "08-04-2026"},
        {3005, "HIIT",        25, 380.0, "Hard",   "10-04-2026"},
        {3006, "Swimming",    50, 610.0, "Hard",   "12-04-2026"}
    };

    int id;

    printf("===== Workout sessions (original) =====\n");
    Display(sessions);

    printf("\nEnter a session ID to search: ");
    scanf("%d", &id);
    Search(sessions, id);

    SortByCalories(sessions);

    printf("\n===== Workout sessions (sorted by calories) =====\n");
    Display(sessions);

    return 0;
}

void Display(SessionData s[])
{
    int i;
    printf("%-6s %-14s %-8s %-10s %-10s %-12s\n",
           "ID", "Exercise", "Dur(min)", "Calories", "Level", "Date");
    for (i = 0; i < SIZE; i++) {
        printf("%-6d %-14s %-8d %-10.2f %-10s %-12s\n",
               s[i].sessionID, s[i].exercise, s[i].durationMin,
               s[i].caloriesBurned, s[i].difficulty, s[i].workoutDate);
    }
}

void Search(SessionData s[], int id)
{
    int i, found = 0;
    for (i = 0; i < SIZE; i++) {
        if (s[i].sessionID == id) {
            printf("\nSession found:\n");
            printf("  Session ID : %d\n",        s[i].sessionID);
            printf("  Exercise   : %s\n",        s[i].exercise);
            printf("  Duration   : %d min\n",    s[i].durationMin);
            printf("  Calories   : %.2f kcal\n", s[i].caloriesBurned);
            printf("  Difficulty : %s\n",        s[i].difficulty);
            printf("  Date       : %s\n",        s[i].workoutDate);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("\nNo session found with ID %d.\n", id);
    }
}

void SortByCalories(SessionData s[])
{
    int i, j;
    SessionData temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (s[j].caloriesBurned > s[j + 1].caloriesBurned) {
                temp     = s[j];
                s[j]     = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
