#include "../main.h"
#include "../headers/graf.h"
#include "../headers/functii.h"
#include "../headers/queue.h"
#include "../headers/liste.h"

Graph *create()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
    {
        printf("memerror");
        exit(-1);
    }

    g->V = 32;

    g->a = (int **)malloc(g->V * sizeof(int *));
    for (int i = 0; i < g->V; i++)
        g->a[i] = (int *)calloc(g->V, sizeof(int));

    if (g->a == NULL)
    {
        printf("memerror");
        exit(-1);
    }
    g->E = 0;
    return g;
}

void printGraph(Graph *g, FILE *file)
{
    int i, j;
    for (i = 0; i < g->V; i++)
    {
        for (j = 0; j < g->V; j++)
            fprintf(file, "%d ", g->a[i][j]);
        fprintf(file, "\n");
    }
}

Graph *makeBattle(Queue *QueueGames, int nr_games, Graph *g, Queue **WinQ, Node **ClasamentList)
{

    team team1, team2;
    Queue *LoseQ = createQueue();

    for (int i = 1; i <= nr_games; i++)
    {
        team1 = deQueue(QueueGames);
        team2 = deQueue(QueueGames);

        if (VersusWinner(team1, team2) == 1) // functii.c
        {
            team1.victorii++;
            g->a[team2.pozitie][team1.pozitie] = 1;
            g->E++;
            enQueue(*WinQ, team1);
            enQueue(LoseQ, team2);
        }
        else
        {
            team2.victorii++;
            g->a[team1.pozitie][team2.pozitie] = 1;
            g->E++;
            enQueue(*WinQ, team2);
            enQueue(LoseQ, team1);
        }
    }

    copyQueueToList(LoseQ, ClasamentList); // queue.c

    return g;
}

Graph *makeGraph(Graph *campionat, Queue *games, int nr_games, Node **ClasamentList)
{
    Queue *WinQ = createQueue();

    for (int i = 0; i < 5; i++)
    {
        campionat = makeBattle(games, nr_games, campionat, &WinQ, ClasamentList);
        nr_games = nr_games / 2;

        deleteQueue(games);
        games = createQueue();

        games = copyQueue(WinQ);

        if (i == 4)
        {
            addAtEnd(ClasamentList, deQueue(WinQ));
        }
        deleteQueue(WinQ);
        WinQ = createQueue();
    }
    return campionat;
}
