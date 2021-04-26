#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define MONTHNUM 12
int getDaysFromMonth(const char * name);
int getDaysFromDay();

struct month {
    char name[10];
    char abbr[4];
    int  days;
    int  monthNum;
};

struct month months[MONTHNUM] = {
    {"January", "JAN", 31, 1},
    {"Feburary", "FEB", 28, 2},
    {"March", "MAR", 31, 3},
    {"April", "APR", 30, 4},
    {"May", "MAY", 31, 5},
    {"June", "JUN", 30, 6},
    {"July", "JUL", 31, 7},
    {"August", "AUG", 31, 8},
    {"September", "SEP", 30, 9},
    {"October", "OCT", 31, 10},
    {"November", "NOV", 30, 11},
    {"December", "DEC", 31, 12},
};

int main(void) {
    // const char *mon = "January";
    // int days = getDays(mon);
    // printf("Up to %s, total days is %d days.\n", mon, days);
    // getchar();
    // ==================================================================
    int days = getDaysFromDay();
    printf("Up to the date, total days is %d days.\n", days);
    getchar();
    getchar();
}

int getDaysFromMonth(const char * name) {
    bool found = false;
    int total = 0;

    for (int i = 0; i < MONTHNUM; i++) {
        total += months[i].days;
        if (strcmp(name, months[i].name) == 0) {
            found = true;
            break;
        }
    }

    if (found) {
        return total;
    } else {
        return -1;
    }
}

int getDaysFromDay() {
    int input;
    int total = 0;
    struct month currentMonth;
    bool found = false;
    printf("Please tell me the year: ");
    scanf("%d", &input);
    printf("\n");

    if (input % 4 == 0) {
        months[1].days = 29;
    } else {
        months[1].days = 28;
    }

    printf("Please tell me the month: ");
    scanf("%d", &input);
    printf("\n");


    if (input > MONTHNUM || input < 0) {
        printf("Please enter a right month index[1-12]\n.");
        return -1;
    }

    for (int i = 0; i < MONTHNUM; i++)
    {
        total += months[i].days;
        if (i == input-1) {
            found = true;
            currentMonth = months[i];
            break;
        }
    }

    printf("Please tell me the days: ");
    scanf("%d", &input);
    printf("\n");

    if (input > currentMonth.days || input < 0) {
        printf("Please enter a right day index[1-%d] in %s", currentMonth.days, currentMonth.name);
    }
    total -= (currentMonth.days - input);
    return total;
}