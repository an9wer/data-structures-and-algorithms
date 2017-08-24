#include <stdio.h>

typedef int item_type;

void insertion_sort(item_type *, int);

/*
 * test
 */
int main(void)
{
    item_type a[] = {5, 4, 3, 2, 1, 6};
    int size = sizeof(a) / sizeof(int);
    insertion_sort(a, size);
    int i;
    for (i = 0; i < size; i++)
        printf("%d\n", a[i]);
    return 0;
}

void insertion_sort(item_type * a, int size)
{
    int i, j;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && a[j] < a[j-1]) {
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }
}
