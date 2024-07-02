#include "node.h"

#include <stdio.h>
#include <stdlib.h>

node *new_node(uint32_t val)
{
    node *n = (node *)malloc(sizeof(node));
    n->n_length = 0;
    n->val = val;
    n->n_size_max = NODE_NEIGHBORS_SIZE_DEFAULT;
    n->neighbors = (void **)calloc(NODE_NEIGHBORS_SIZE_DEFAULT, sizeof(node *));

    for (int i = 0; i < NODE_NEIGHBORS_SIZE_DEFAULT; i++)
    {
        n->neighbors[i] = (void *)calloc(NODE_NEIGHBORS_SIZE_DEFAULT, sizeof(node *));
    }

    return n;
}

void clean_node(node *n)
{
    for (size_t i = 0; i < n->n_size_max; i++)
    {
        free(n->neighbors[i]);
    }
    free(n->neighbors);
    free(n);
}

node *get_neighbor(node *n, size_t index)
{
    void *neighbor_ptr = n->neighbors[index];
    node *neighbor = (node *)(neighbor_ptr);

    return neighbor;
}