#include "main.h"
Graph *create()
{
    Graph *campionat = (Graph *)malloc(sizeof(Graph));
    if (campionat == NULL)
    {
        printf("memerror");
        exit(-1);
    }

    campionat->V = 32;

    campionat->a = (int **)malloc(campionat->V * sizeof(int *));
    for (int i = 0; i < campionat->V; i++)
        campionat->a[i] = (int *)calloc(campionat->V, sizeof(int));

    if (campionat->a == NULL)
    {
        printf("memerror");
        exit(-1);
    }
    campionat->E = 0;

    for (int i = 0; i < campionat->V; i++)
        for (int j = 0; j < campionat->V; j++)
        {
        }
}