#include "main.h"
#include "./headers/graf.h"
#include "./headers/functii.h"
#include "./headers/queue.h"
#include "./headers/liste.h"

int main(int argc, char *argv[])
{
    FILE *fileInput = fopen(argv[1], "rb");
    fileOpenVerification(fileInput);

    FILE *fileOutput = fopen(argv[2], "wb");
    fileOpenVerification(fileOutput);

    FILE *fileOutputScor = fopen(argv[3], "wb");
    fileOpenVerification(fileOutputScor);

    Node *TeamList = NULL;
    addToListFromFile(&TeamList, fileInput);
    fclose(fileInput);

    Graph *campionat = create();
    Queue *games = createQueue();

    QueueExtractFromList(&games, TeamList);
    deleteList(&TeamList);

    int nr_games = campionat->V / 2;

    Node *ClasamentList = NULL;

    campionat = makeGraph(campionat, games, nr_games, &ClasamentList);
    printGraph(campionat, fileOutput);

    printPrestigiu(fileOutputScor, ClasamentList);

    deleteList(&ClasamentList);
    deleteQueue(games);

    return 0;
}