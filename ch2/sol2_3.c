/* Computes volume of sphere */

#include <stdio.h>

#define SCALE_FACTOR (4.0f/3.0f)
#define PI 3.14159

int main(void)
{
    float volume, radius;

    printf("Enter radius: ");
    scanf("%f", &radius);

    volume = SCALE_FACTOR * PI * radius * radius * radius;

    printf("Volume: %.5f m^3\n", volume);

    return 0;
}