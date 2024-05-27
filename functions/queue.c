#include "../main.h"
#include "../headers/queue.h"
#include "../headers/liste.h"
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

Queue *copyQueue(Queue *q)
{
    if (q == NULL)
    {
        return NULL;
    }
    Queue *newQueue = createQueue();
    Node *current = q->front;

    while (current != NULL)
    {
        enQueue(newQueue, current->val);
        current = current->next;
    }
    return newQueue;
}

void reverseQueue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        return;
    }
    team temp = deQueue(q);
    reverseQueue(q);
    enQueue(q, temp);
}

void copyQueueToList(Queue *LoseQ, Node **ClasamentList)
{
    reverseQueue(LoseQ);
    while (!isEmptyQueue(LoseQ))
    {
        addAtEnd(ClasamentList, deQueue(LoseQ));
    }
}