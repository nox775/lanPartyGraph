#include "../main.h"
#include "../headers/graf.h"
#include "../headers/functii.h"
#include "../headers/queue.h"
#include "../headers/stack.h"

int isEmptyStack(Node *top)
{
    return top == NULL;
}

void push(Node **top, team v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *top;
    *top = newNode;
}

team pop(Node **top)
{
    if (isEmptyStack(*top))
    {
        printf("Stiva goala\n");
        exit(-1);
    }

    Node *temp = (*top);

    team aux = temp->val;
    *top = (*top)->next;
    free(temp);
    return aux;
}

void deleteStack(Node **top)
{
    Node *temp;
    while (!isEmptyStack(*top))
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}