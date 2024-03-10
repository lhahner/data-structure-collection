#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct mygraph graph;

graph *create_graph(int numnodes);
void destroy_graph(graph *g);
void print_graph(graph *g);
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node);
bool add_edge(graph *g, unsigned int from_node, unsigned int to_node);

int main()
{
    graph *g1 = create_graph(5);
    add_edge(g1, 0, 2);
    print_graph(g1);
}

struct mygraph
{
    int numnodes;
    int **edges;
};

graph *
create_graph(int numnodes)
{
    graph *g = malloc(sizeof(*g));
    if (g == NULL)
    {
        return NULL;
    }
    g->numnodes = numnodes;
    g->edges = calloc(sizeof(bool *), g->numnodes);
    if (g->edges == NULL)
    {
        free(g);
        return NULL;
    }

    for (int i = 0; i < g->numnodes; i++)
    {
        g->edges[i] = calloc(sizeof(bool), g->numnodes);
        if (g->edges[i] == NULL)
        {
            destroy_graph(g);
            return NULL;
        }
    }
    return g;
}

void destroy_graph(graph *g)
{
    if (g->edges == NULL)
    {
        return;
    }
    for (int i = 0; i < g->numnodes; i++)
    {
        if (g->edges[i] != NULL)
        {
            free(g->edges[i]);
        }
    }
    free(g->edges);
}
bool has_edge(graph *g, unsigned int from_node, unsigned int to_node)
{
    return g->edges[from_node][to_node];
}

bool add_edge(graph *g, unsigned int from_node, unsigned int to_node)
{
    if (has_edge(g, from_node, to_node))
    {
    }

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