#include <stdio.h>

typedef int item_type;

int partition(item_type *, int, int);
void quicksort(item_type *, int, int);

/*
 * test
 */
int main(void)
{
    item_type a[] = {7, 9, 5, 4, 3, 2, 8};
    quicksort(a, 0, 6);
    int i;
    for (i = 0; i < sizeof(a) / sizeof(item_type); i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}

int partition(item_type s[], int l, int h)
{
    int i;          // counter
    int p;          // pivot element index
    int firsthigh;  // divider position for pivot element
    int temp;

    p = h;          // pivot is the last element of partition
    firsthigh = l;
    for (i = l; i < h; i++)
        if (s[i] < s[p]) {
            // swap(&s[i], &s[firsthight]);
            temp = s[i];
            s[i] = s[firsthigh];
            s[firsthigh] = temp;
            firsthigh++;
        }
    // swap(&s[p], &s[firsthigh]);
    temp = s[p];
    s[p] = s[firsthigh];
    s[firsthigh] = temp;

    return p;
}

void quicksort(item_type s[], int l, int h)
{
    /*
     * param l: the smallest index of s
     * param h: the largest index of s
     */
    int p;
    if ((h-l) > 0) {
        p = partition(s, l, h);
        quicksort(s, l, p-1);
        quicksort(s, p+1, h);
    }
}
