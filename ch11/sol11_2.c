/* Finds closest departure time */

#include <stdio.h>

int dept_times[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
int arr_times[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

int d1 = (1305 + 480 - 1440) / 2;
int d2 = (480 + 583) / 2;
int d3 = (583 + 679) / 2;
int d4 = (679 + 767) / 2;
int d5 = (767 + 840) / 2;
int d6 = (840 + 945) / 2;
int d7 = (945 + 1140) / 2;
int d8 = (1140 + 1305) / 2;

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int time, hours, minutes, departure_time, arrival_time, d_hour, d_minute, a_hour, a_minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    time = hours * 60 + minutes;

    find_closest_flight(time, &departure_time, &arrival_time);

    d_hour = departure_time / 60;
    d_minute = departure_time % 60;
    a_hour = arrival_time / 60;
    a_minute = arrival_time % 60;

    if (departure_time < 720 && arrival_time < 720) 
        printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d a.m.\n", d_hour, d_minute,
            a_hour, a_minute);
    else if (departure_time < 720 && arrival_time >= 720)
        printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d p.m.\n", d_hour, d_minute,
            (a_hour % 12 == 0) ? 12 : a_hour % 12, a_minute);
    else 
        printf("Closest departure time is %d:%.2d p.m., arriving at %d:%.2d p.m.\n", (d_hour % 12 == 0) ? 12 : d_hour % 12,
            d_minute, (a_hour % 12 == 0) ? 12 : a_hour % 12, a_minute);

    return 0;
}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    if (desired_time <= d1) {
        *departure_time = dept_times[7];
        *arrival_time = arr_times[7];
    } else if (desired_time > d1 && desired_time <= d2) {
        *departure_time = dept_times[0];
        *arrival_time = arr_times[0];
    } else if (desired_time > d2 && desired_time <= d3) {
        *departure_time = dept_times[1];
        *arrival_time = arr_times[1];
    } else if (desired_time > d3 && desired_time <= d4) {
        *departure_time = dept_times[2];
        *arrival_time = arr_times[2];
    } else if (desired_time > d4 && desired_time <= d5) {
        *departure_time = dept_times[3];
        *arrival_time = arr_times[3];
    } else if (desired_time > d5 && desired_time <= d6) {
        *departure_time = dept_times[4];
        *arrival_time = arr_times[4];
    } else if (desired_time > d6 && desired_time <= d7) {
        *departure_time = dept_times[5];
        *arrival_time = arr_times[5];
    } else if (desired_time > d7 && desired_time <= d8) {
        *departure_time = dept_times[6];
        *arrival_time = arr_times[6];
    } else {
        *departure_time = dept_times[7];
        *arrival_time = arr_times[7];
    }
}

