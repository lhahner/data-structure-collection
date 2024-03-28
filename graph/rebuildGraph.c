#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct graph
{
    int numnodes;
    int **edges;
} graph;

graph *createGraph(int numnodes);
bool addEdge(graph *g, unsigned int from_node, unsigned to_node);
void print_graph(graph *g);

int main()
{
    graph* g = createGraph(5);
    addEdge(g, 1, 2);
    print_graph(g);
    return 1;
}

graph *createGraph(int numnodes)
{
    graph *g = malloc(sizeof(*g));
    g->numnodes = numnodes;
    g->edges = calloc(sizeof(bool *), g->numnodes);
    if(g->edges == NULL){
        free(g);
        return NULL;
    }
    for (int i = 0; i < g->numnodes; i++)
    {
        g->edges[i] = calloc(sizeof(bool *), g->numnodes);
        if(g->edges[i] == NULL){
            return NULL;
        }
    }
    return g;
}

bool addEdge(graph *g, unsigned int from_node, unsigned to_node){
    g->edges[from_node][to_node] = true;
    return true;
}

void print_graph(graph *g)
{
    printf("digraph {\n");
    for (int from = 0; from < g->numnodes; from++)
    {
        for (int to = 0; to < g->numnodes; to++)
        {
            if (g->edges[from][to])
            {
                printf("%d -> %d,\n", from, to);
            }
        }
    }
    printf("}\n");
}