#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct main
{
    int pozitie;
    char *nume;
    float scor;
} team;

typedef struct
{

    int V;
    int E;
    int **a;
} Graph;

struct elem
{
    team val;
    struct elem *next;
};
typedef struct elem Node;
