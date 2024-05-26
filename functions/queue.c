#include "../main.h"
#include "../headers/queue.h"
#include "../headers/stack.h"

Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, team v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = NULL;

    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;
}

int isEmptyQueue(Queue *q)
{
    return (q->front == NULL);
}

team deQueue(Queue *q)
{
    Node *aux;
    team d;
    if (isEmptyQueue(q))
    {
        printf("Coada goala\n");
        exit(-1);
    }

    aux = q->front;
    d = aux->val;
    q->front = (q->front)->next;
    free(aux);
    return d;
}

void deleteQueue(Queue *q)
{
    Node *aux;
    while (!isEmptyQueue(q))
    {
        aux = q->front;
        q->front = q->front->next;
        free(aux);
    }
    free(q);
}

void QueueExtractFromList(Queue **QueueGames, Node *listTeams)
{
    // Puna in coada echipele din lista
    while (listTeams != NULL)
    {
        enQueue(*QueueGames, listTeams->val);
        listTeams = listTeams->next;
    }
}

void QueueExtractFromStack(Queue **QueueGames, Node *WinStack)
{
    // Pune in coada echipele victorioase din stiva
    while (WinStack != NULL)
    {
        enQueue(*QueueGames, WinStack->val);
        WinStack = WinStack->next;
    }
    deleteStack(&WinStack);
}