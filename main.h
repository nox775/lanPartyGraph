#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define maxName 50
#define epsilon 0.001
#define runde 5

typedef struct main
{
    int pozitie;
    char *nume;
    float scor;
    int victorii;
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

struct Q
{
    Node *front, *rear;
};
typedef struct Q Queue;
