/* Modifies chapter 5, programming project 8 to store the departure and arrival times in arrays */

#include <stdio.h>

int main(void)
{
    int hour, minute, total, i, time, prev_time, departure_hour, departure_minute, arrival_hour, arrival_minute;
    int departure_times[] = {480, 583, 679, 767, 840, 945, 1140, 1305},
        arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    total = hour * 60 + minute;

    prev_time = (departure_times[7] + departure_times[0] - 1440) / 2;
    for (i = 0; i < 8; i++) {
        if (i == 7) {
            time = (departure_times[7] + departure_times[0] - 1440) / 2 + 1440;
            total += 1440;
        } else
            time = (departure_times[i] + departure_times[i+1]) / 2;

        if (total > prev_time && total <= time) {
            departure_hour = departure_times[i] / 60 % 12;
            departure_minute = departure_times[i] % 60;
            arrival_hour = arrival_times[i] / 60 % 12;
            arrival_minute = arrival_times[i] % 60;

            if (departure_times[i] < 720 && arrival_times[i] < 720)
                printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d a.m.\n", departure_hour, departure_minute,
                    arrival_hour, arrival_minute);
            else if (departure_times[i] < 720 && arrival_times[i] >= 720)
                printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d p.m.\n", departure_hour, departure_minute,
                    arrival_hour, arrival_minute);
            else 
                printf("Closest departure time is %d:%.2d p.m., arriving at %d:%.2d p.m.\n", departure_hour, departure_minute,
                    arrival_hour, arrival_minute);
        }
        prev_time = time;
    }

    return 0;
}