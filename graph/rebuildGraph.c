#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <rebuildGraph.h>

typedef struct graph
{
    int numnodes;
    int **edges;
} graph;

int main()
{
    return 1;
}

graph *createGraph(int numnodes)
{
    graph *g = malloc(sizeof(*g));
    g->numnodes;
    g->edges = calloc(sizeof(bool *), g->numnodes);
    for (int i = 0; i < g->numnodes; i++)
    {
        g->edges[i] = calloc(sizeof(bool *), g->numnodes);
    }
}