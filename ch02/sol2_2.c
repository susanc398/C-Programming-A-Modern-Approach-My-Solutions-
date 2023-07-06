/* Computes volume of sphere with 10-meter radius */

#include <stdio.h>

#define SCALE_FACTOR (4.0f/3.0f)
#define PI 3.14159
#define RADIUS 10

int main(void)
{
    float volume;

    volume = SCALE_FACTOR * PI * RADIUS * RADIUS * RADIUS;

    printf("Volume: %.5f m^3\n", volume);

    return 0;
}