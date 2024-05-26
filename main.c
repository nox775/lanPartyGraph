#include "main.h"
#include "./headers/graf.h"
#include "./headers/functii.h"
#include "./headers/queue.h"
#include "./headers/stack.h"

int main(int argc, char *argv[])
{
    FILE *fileInput = fopen(argv[1], "rb");
    FILE *fileOutput = fopen(argv[2], "wb");

    Node *TeamList = NULL;
    addToListFromFile(&TeamList, fileInput);
    fclose(fileInput);

    Graph *campionat = create();
    Queue *games = createQueue();
    QueueExtractFromList(&games, TeamList);
    deleteList(&TeamList);
    int nr_games = campionat->V / 2;

    Node *WinStack = NULL;

    campionat = makeGraph(campionat, games, WinStack, nr_games);
    printGraph(campionat, fileOutput);

    return 0;
}