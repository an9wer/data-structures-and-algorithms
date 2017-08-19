#include <stdio.h>
#include <stdlib.h>

typedef int item_type;
typedef struct heap {
    int size;           // size of the allocated memory
    int count;          // count of the elements in the heap
    item_type * ha;     // pointer to heap array
} heap;

heap *init(heap *, int);
void max_heapify(heap *, int);
heap *insert(heap *, item_type);
item_type find_maximum(heap *);
heap *delete_maximum(heap *);

/*
 * test
 */
int main(void)
{
    //heap hi, *h = &hi;
    heap *h = malloc(sizeof(heap));
    init(h, 6);
    h = insert(h, 1);
    h = insert(h, 2);
    h = insert(h, 3);
    h = insert(h, 4);
    h = insert(h, 5);
    h = insert(h, 6);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = delete_maximum(h);
    printf("%d\n", find_maximum(h));
    h = insert(h, 2);
    printf("%d\n", find_maximum(h));
    h = insert(h, 3);
    printf("%d\n", find_maximum(h));
    return 0;
}

heap *init(heap *h, int size)
{
    h->size = size;
    h->count = 0;
    h->ha = malloc(sizeof(item_type) * size);
    if (h->ha == NULL)
        return NULL;
    return h;
}

void max_heapify(heap *h, int i)
{
    int l = 2 * i;          // left child
    int r = 2*i + 1;        // right child
    int largest;
    if (l <= h->count && h->ha[l-1] > h->ha[i-1])
        largest = l;
    else
        largest = i;
    if (r <= h->count && h->ha[r-1] > h->ha[largest-1])
        largest = r;
    if (largest != i) {
        item_type temp = h->ha[i-1];
        h->ha[i-1] = h->ha[largest-1];
        h->ha[largest-1] = temp;
        max_heapify(h, largest);
    }

}

heap *insert(heap *h, item_type x)
{
    if (h->count < h->size) {
        h->ha[h->count++] = x;
        int count;
        for (count = h->count; count > 1 && h->ha[count/2 - 1] < h->ha[count-1];
                count /= 2) {
            h->ha[count - 1] = h->ha[count/2 - 1];
            h->ha[count/2 - 1] = x;
        }
        return h;
    }
}

item_type find_maximum(heap *h)
{
    if (h->count > 0)
        return h->ha[0];
    return -1;
}

heap *delete_maximum(heap *h)
{
    if (h->count > 0) {
        h->ha[0] = h->ha[h->count-- - 1];
        max_heapify(h, 1);
    }
    return h;
}
