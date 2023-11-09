/* Sorts an array of integers using selection sort algorithm */

#include <stdio.h>

#define N 10

void selection_sort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    selection_sort(a, 0, N - 1);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void selection_sort(int a[], int low, int high)
{
    int sorted;

    if (low >= high) return;
    sorted = split(a, low, high);
    selection_sort(a, low, sorted - 1);
}

int split(int a[], int low, int high)
{
    int max = a[high];

    for (;;) {
        if (low < high && a[low] <= max)
            low++;
        if (low >= high) break;
        if (a[low] > max) {
            a[high] = a[low];
            a[low++] = max;
            max = a[high];
        }
    }

    return high;
}

