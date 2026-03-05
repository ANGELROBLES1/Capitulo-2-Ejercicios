#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 5
#define MAXWORD 100

struct nlist {
    struct nlist *next;
    char *name;
    int count;
};

struct nlist *hashtab[HASHSIZE];

/* Prototipos */
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *s);
char *strdup_local(char *s);
int strcasecmp_local(char *s, char *t);
int getword(char *word, int lim);

/* Hash usando tolower */
unsigned hash(char *s) {
    unsigned hashval = 0;
    for (; *s != '\0'; s++)
        hashval = tolower(*s) + 31 * hashval;
    return hashval % HASHSIZE;
}

/* Comparación sin distinguir mayúsculas */
int strcasecmp_local(char *s, char *t) {
    while (tolower(*s) == tolower(*t)) {
        if (*s == '\0')
            return 0;
        s++;
        t++;
    }
    return tolower(*s) - tolower(*t);
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcasecmp_local(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *s) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(s)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup_local(s)) == NULL)
            return NULL;
        np->count = 1;
        hashval = hash(s);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        np->count++;
    }
    return np;
}

char *strdup_local(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* Leer palabra */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    while ((c = getchar()) != EOF && !isalpha(c))
        ;

    if (c == EOF)
        return EOF;

    *w++ = c;

    while (--lim > 0) {
        c = getchar();
        if (!isalpha(c)) {
            ungetc(c, stdin);
            break;
        }
        *w++ = c;
    }

    *w = '\0';
    return word[0];
}

int main() {
    char word[MAXWORD];
    struct nlist *np;
    int i;

    while (getword(word, MAXWORD) != EOF)
        install(word);

    for (i = 0; i < HASHSIZE; i++)
        for (np = hashtab[i]; np != NULL; np = np->next)
            printf("%s: %d\n", np->name, np->count);

    return 0;
}
