#include <stdio.h>
#include <stdlib.h>

typedef int item_type;
typedef struct stack {
    item_type item;
    struct stack * next;
} stack;
void push(item_type, stack **);
void pop(stack **);

/*
 * test
 */
int main(void)
{
    stack *pt;      // pt point to NULL
    push(1, &pt);
    push(2, &pt);
    push(3, &pt);
    pop(&pt);
    pop(&pt);
    pop(&pt);
    pop(&pt);
    pop(&pt);
    pop(&pt);
    
    return 0;
}

void push(item_type x, stack **s)
{
    stack *p = malloc(sizeof(stack));
    p->item = x;
    p->next = *s;
    *s = p;
    printf("push: %2d\n", x);       // just for test
}

void pop(stack **s)
{
    if (*s != NULL) {
        printf("pop : %2d\n", (*s)->item);     // just for test
        stack *p = (*s)->next;
        free(*s);
        *s = p;
    }
    else
        printf("stack is empty now!\n");
}
