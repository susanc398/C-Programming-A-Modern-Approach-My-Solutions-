/* Finds closest departure time of a flight */

#include <stdio.h>
#include <stdlib.h>

int search_times(int table[], int n, int time)
{
    int left = 0, right = n - 1, mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        if (table[mid] < time)
            left = mid + 1;
        else if (table[mid] > time)
            right = mid - 1;
        else
            return table[mid];
    }

    if (abs(time - table[mid-1]) > abs(time - table[mid]))
        return table[mid];
    else
        return table[mid-1];
}

int main(void)
{
    int hour, minute, departure;
    int timeTable[8] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47,
        14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    minute += hour * 60;

    departure = search_times(timeTable, 8, minute);
    
    switch (departure) {
        case 8 * 60:
            printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
            break;
        case 9 * 60 + 43:
            printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
            break;
        case 11 * 60 + 19:
            printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
            break;
        case 12 * 60 + 47:
            printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
            break;
        case 14 * 60:
            printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
            break;
        case 15 * 60 + 45:
            printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
            break;
        case 19 * 60:
            printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
            break;
        case 21 * 60 + 45:
            printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
            break;
    }

    return 0;
}