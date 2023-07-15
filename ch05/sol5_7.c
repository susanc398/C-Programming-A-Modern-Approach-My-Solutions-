/* Finds the largest and smallest of four digits */

#include <stdio.h>

int main(void)
{
    int i1, i2, i3, i4, largest, smallest;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &i1, &i2, &i3, &i4);

    smallest = largest = i1;

    if (i2 < smallest)
        smallest = i2;
    if (i3 < smallest)
        smallest = i3;
    if (i4 < smallest)
        smallest = i4;

    if (i2 > largest)
        largest = i2;
    if (i3 > largest)
        largest = i3;
    if (i4 > largest)
        largest = i4;

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}