/* Prints a one-year reminder list */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum length of reminders */
#define MSG_LEN 60      /* max length of reminder messages */

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[22], msg_str[MSG_LEN+1];
    int month, day, hours, minutes, i, j, num_remind = 0;

    while (1) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter date, time, and reminder: ");
        scanf(" %d/ %d", &month, &day);
        if (month == 0 || day == 0)
            break;
        else if (day < 0 || day > 31) {
            printf("Please enter valid day\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        scanf(" %d: %d", &hours, &minutes);
        sprintf(day_str, "%2d/%2.2d %2d:%2.2d", month, day, hours, minutes);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }
    printf("\nDate  Time  Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf("%s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}