#include <stdio.h>

typedef int item_type;

void merge(item_type s[], int low, int middle, int high);
void mergesort(item_type s[], int low, int high);

/*
 * test
 */
int main(void)
{
    item_type s[] = {7, 6, 5, 4, 3, 2, 1};
    mergesort(s, 1, 7);
    int i;
    for (i = 0; i < 7; i++)
        printf("%d\n", s[i]);
    return 0;
}

void merge(item_type s[], int low, int middle, int high)
{
    int i;
    item_type buf1[middle-low+1], buf2[high-middle];
    for (i = 0; i < middle-low+1; i++)
        buf1[i] = s[low+i-1];
    for (i = 0; i < high-middle; i++)
        buf2[i] = s[middle+i];
    int j, k;
    i = j = k = 0;
    while (i < high-low+1) {
        if (j < middle-low+1 && buf1[j] <= buf2[k])
            s[low + i++ - 1] = buf1[j++];
        else if (k < high-middle && buf1[j] > buf2[k])
            s[low + i++ - 1] = buf2[k++];
        else if (j < middle-low+1 && k >= high-middle)
            s[low + i++ - 1] = buf1[j++];
        else if (j >= middle-low+1 && k < high-middle)
            s[low + i++ - 1] = buf2[k++];
    }
}

void mergesort(item_type s[], int low, int high)
{
    int middle;
    if (low < high) {
        middle = (low + high) / 2;
        mergesort(s, low, middle);
        mergesort(s, middle+1, high);
        merge(s, low, middle, high);
    }
}
