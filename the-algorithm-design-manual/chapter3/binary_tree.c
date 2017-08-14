#include <stdio.h>
#include <stdlib.h>

typedef int item_type;
typedef struct tree {
    item_type item;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
} tree;

tree *search_tree(tree *, item_type);
tree *find_minimum(tree *);
void traverse_tree(tree *);
void insert_tree(tree **, item_type, tree *);
void delete_tree(tree **, item_type);


/*
 * test
 */
int main(void)
{
    tree * pt;
    delete_tree(&pt, 3);
    insert_tree(&pt, 2, NULL);
    insert_tree(&pt, 1, NULL);
    insert_tree(&pt, 0, NULL);
    insert_tree(&pt, 4, NULL);
    insert_tree(&pt, 3, NULL);
    insert_tree(&pt, 5, NULL);
    traverse_tree(pt);
    delete_tree(&pt, 2);
    delete_tree(&pt, 3);
    delete_tree(&pt, 1);
}

tree *search_tree(tree *l, item_type x)
{
    if (l == NULL)
        return NULL;
    if (l->item == x)
        return l;
    if (x < l->item)
        return search_tree(l->left, x);
    return search_tree(l->right, x);
}

tree *find_minimum(tree *t)
{
    tree *min;
    if (t == NULL)
        return NULL;
    min = t;
    while (min->left != NULL)
        min = min->left;
    return min;
}

void traverse_tree(tree *l)
{
    if (l != NULL) {
        traverse_tree(l->left);
        printf("%d ", l->item);
        traverse_tree(l->right);
    }
}

void insert_tree(tree **l, item_type x, tree *parent)
{
    tree *p;
    if (*l == NULL) {
        p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;     // backlink into parent's left or right child
        return;     // note that we must have this statement
    }
    if (x < (*l)->item)
        insert_tree(&((*l)->left), x, *l);
    else
        insert_tree(&((*l)->right), x, *l);
}

void delete_tree(tree **l,  item_type x)
{
    tree *p = search_tree(*l, x);
    if (p != NULL) {
        /* p->right is NULL and p->left is NULL or not NULL */
        if (p->right == NULL) {
            if (p->parent == NULL)
                *l = p->left;
            else {
                if (p->parent->left == p)
                    p->parent->left = p->left;
                else
                    p->parent->right = p->left;
            }
            if (p->left != NULL)
                p->left->parent = p->parent;
        }
        /* p->left is NULL and p->right is NULL or not NULL */
        else if (p->left == NULL) {
            if (p->parent == NULL)
                *l = p->right;
            else {
                if (p->parent->left == p)
                    p->parent->left = p->right;
                else
                    p->parent->right = p->right;
            }
            if (p->right != NULL)
                p->right->parent = p->parent;
        }
        /* p->left is not NULL and p->right is not NULL */
        else {
            tree *min = find_minimum(p->right);
            /* min is the right child of p */
            if (min == p->right) {
                if (p->parent == NULL)
                    *l = min;
                else {
                    if (p->parent->left == p)
                        p->parent->left = min;
                    else
                        p->parent->right = min;
                }
                min->parent = p->parent;

                min->left = p->left;
                p->left->parent = min;
            }
            /* min is not the right child of p */
            else {
                /* first replace min by its own right child */
                min->parent->left = min->right;
                if (min->right != NULL)
                    min->right->parent = min->parent;
                /* then replace p by min */
                if (p->parent == NULL)
                    *l = min;
                else {
                    if (p->parent->left == p)
                        p->parent->left = min;
                    else
                        p->parent->right = min;
                }
                min->parent = p->parent;
                min->left = p->left;
                p->left->parent = min;
                min->right = p->right;
                p->right->parent = min;
            }
        }

        free(p);
    }
}
