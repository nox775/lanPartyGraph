#include "main.h"
#include "graf.h"

int main(char *argv, int argc)
{
    FILE *fileInput = fopen(argv[1], "r");

    Node *TeamList = NULL;
    addToListFromFile(fileInput, TeamList);

    return 0;
}