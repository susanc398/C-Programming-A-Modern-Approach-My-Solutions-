/* Finds closest departure time (struct version) */

#include <stdio.h>
#include <stdlib.h>

struct times {
    int departure_time;
    int arrival_time;
};

const struct times flights[] = 
  {{480, 616}, {583,  712}, {679,   811}, {767,   900},
   {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}};

int binary_search(int time, int low, int high);

int main()
{
    int hours, minutes, total_time, idx;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    total_time = hours * 60 + minutes;

    idx = binary_search(total_time, 0, 7);

    if (flights[idx].departure_time < 720 && flights[idx].arrival_time < 720)
        printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d a.m.\n", 
          flights[idx].departure_time / 60, flights[idx].departure_time % 60,
          flights[idx].arrival_time / 60, flights[idx].arrival_time % 60);
    else if (flights[idx].departure_time < 720 && flights[idx].arrival_time >= 720)
        printf("Closest departure time is %d:%.2d a.m., arriving at %d:%.2d p.m.\n", 
          flights[idx].departure_time / 60, flights[idx].departure_time % 60,
          flights[idx].arrival_time / 60, flights[idx].arrival_time % 60);
    else 
        printf("Closest departure time is %d:%.2d p.m., arriving at %d:%.2d p.m.\n", 
          flights[idx].departure_time / 60, flights[idx].departure_time % 60,
          flights[idx].arrival_time / 60, flights[idx].arrival_time % 60);

    return 0;
}

int binary_search(int time, int low, int high)
{
    int mid;
    if (time < 258)
        time += 1440;

    while (low <= high) {
        mid = (low + high) / 2;

        if (time < flights[mid].departure_time)
            high = mid - 1;
        else if (time > flights[mid].departure_time)
            low = mid + 1;
        else if (time == flights[mid].departure_time)
            return mid;
    }

    if (abs(mid - low) < abs(mid - high)) {
        if (abs(flights[low].departure_time - time) < abs(flights[mid].departure_time - time))
            return low;
    } else {
        if (abs(flights[high].departure_time - time) < abs(flights[mid].departure_time - time))
            return high;
    }

    return mid;
}