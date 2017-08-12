#include <stdio.h>
#include <stdlib.h>

typedef int item_type;
typedef struct list {
    item_type item;
    struct list *next;
} list;

list *search_list(list *, item_type);
void insert_list(list **, item_type);
list * predecessor_list(list *, item_type);
void delete_list(list **, item_type);

/*
 * test
 */
int main(void)
{
    list *pt;               // pt point to NULL
    delete_list(&pt, 1);    // can't delete
    insert_list(&pt, 2);    // ok
    insert_list(&pt, 3);    // ok
    delete_list(&pt, 2);    // ok
    delete_list(&pt, 3);    // ok
    delete_list(&pt, 0);    // can't delete

    return 0;
}

list *search_list(list *l, item_type x)
{
    if (l == NULL) {
        printf("can't find: %2d\n", x);     // just for test
        return NULL;
    }
    if (l->item == x)
        return l;
    return search_list(l->next, x);
}

/*
 * always insert x into the first element of list
 */
void insert_list(list **l, item_type x)
{
    list *p;
    p = malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
    printf("insert: %2d\n", x);     // just for test
}

list *predecessor_list(list *l, item_type x)
{
    /* if x not in list or x is the first item in list */
    if (l == NULL || l->next == NULL) {
        return NULL;
    }
    if (l->next->item == x)
        return l;
    return predecessor_list(l->next, x);
}

void delete_list(list **l, item_type x)
{
    list *p;        // pointer
    list *pred;     // predecessor pointer

    p = search_list(*l, x);
    if (p != NULL) {
        pred = predecessor_list(*l, x);
        /* if pointer p point to the first item of list */
        if (pred == NULL)
            *l = p->next;
        else
            pred->next = p->next;
        free(p);
        printf("delete: %2d\n", x);     // just for test
    }
}
