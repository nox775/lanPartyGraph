#include "../main.h"
#include "../headers/functii.h"
#include "../headers/liste.h"

void addToListFromFile(Node **head, FILE *fin)
{
    // scrie din fisier in lista
    for (int i = 0; i < 32; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));

        newNode->val.nume = (char *)malloc(maxName * sizeof(char));

        if (!newNode->val.nume)
        {
            printf("Memory allocation failed\n");
            exit(-1);
        }

        fscanf(fin, "%f %[^\n]", &(newNode->val.scor), newNode->val.nume);
        newNode->val.pozitie = i;
        newNode->val.victorii = 0;

        newNode->next = *head;
        *head = newNode;
    }
}

void addAtBeginning(Node **head, team buffer)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->val.nume = (char *)malloc(maxName * sizeof(char));

    if (!newNode->val.nume)
    {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    newNode->val.scor = buffer.scor;
    newNode->val.victorii = buffer.victorii;
    strcpy(newNode->val.nume, buffer.nume);
    newNode->next = *head;
    *head = newNode;
}
void addAtEnd(Node **head, team v)
{
    Node *aux = *head;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL)
        addAtBeginning(head, v);
    else
    {
        while (aux->next != NULL)
            aux = aux->next;
        aux->next = newNode;
        newNode->next = NULL;
    }
}

void deleteList(Node **head)
{
    Node *headcopy;

    while (*head != NULL)
    {
        headcopy = (*head)->next;
        free(*head);
        *head = headcopy;
    }
    *head = NULL;
}