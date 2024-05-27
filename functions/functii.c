#include "../main.h"
#include "../headers/functii.h"
#include "../headers/queue.h"
#include "../headers/liste.h"

void fileOpenVerification(FILE *file)
{
    if (file == NULL)
    {
        printf("File doesnt open");
        perror("Fille Error");
        exit(-1);
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
        if (strcmp(t1.nume, t2.nume) > 0)
            return 1;
        else
            return 0;
    }
    else if (t1.scor > t2.scor)
        return 1;
    else
        return 0;
}

void printPrestigiu(FILE *file, Node *ClasamentList)
{
    float pr;
    float q = 0.15;
    float runde = 5;
    while (ClasamentList)
    {
        pr = (q * powf(2 - q, ClasamentList->val.victorii)) / (powf(2, runde + 1) + powf(2 - q, runde + 1) * (q - 1));
        fprintf(file, "%.4f %s\n", pr, ClasamentList->val.nume);
        ClasamentList = ClasamentList->next;
    }
}
