/*
 * following `C programing language 6.6`
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

typedef struct nlist {
    struct nlist *next;
    char *name;         // key
    char *defn;         // value
} nlist;

nlist *hashtab[HASHSIZE];

/* 
 * In my system, strdup() is already in string.h,
 * So just comment here.
 *
 * char *strdup(char *);
 *
 */
unsigned hash(char *);
nlist *lookup(char *);
nlist *install(char *, char *);
nlist *uninstall(char *);


/*
 * test
 */
int main(void)
{
    nlist *pt;
    pt = uninstall("name");
    pt = install("a", "apple");
    pt = install("b", "bird");
    pt = uninstall("b");
    pt = uninstall("a");
    pt = uninstall("a");
}

/*
 * In my system, strdup() is already in string.h,
 * So just comment here.
 *
 * char *strdup(char *s)
 * {
 *     char *p;
 *     p = (char *) malloc(strlen(s) + 1);
 *     if (p != NULL)
 *         strcpy(p, s);
 *     return p;
 * }
 *
 */

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    //return 1;       // just for test
    return hashval % HASHSIZE;
}

nlist *lookup(char *s)
{
    nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

nlist *install(char *name, char *defn)
{
    nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/*
 * uninstall operation writed by myself
 */
nlist *uninstall(char *name)
{
    nlist *np, *bnp;
    unsigned hashval;
    if ((np = lookup(name)) == NULL)
        return NULL;
    else {
        hashval = hash(name);
        bnp = hashtab[hashval];
        if (bnp == np) {
            hashtab[hashval] = np->next;
        }
        else {
            for (bnp = hashtab[hashval]; bnp->next != np; bnp = bnp->next)
                ;
            bnp->next = np->next;
        }
        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
        return bnp;
    }
}
