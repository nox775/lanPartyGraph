#include "../main.h"
#include "../headers/functii.h"
#include "../headers/queue.h"
#include "../headers/stack.h"

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

int float_equal(float a, float b)
{
    return fabs(a - b) < epsilon;
}

int VersusWinner(team t1, team t2)
{
    if (float_equal(t1.scor, t2.scor))
    {
        if (strcmp(t1.nume, t2.nume) < 0) // posibila greseala
            return 1;
        else
            return 0;
    }
    else if (t1.scor > t2.scor)
        return 1;
    else
        return 0;
}
