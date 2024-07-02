#ifndef NODE_H
#define NODE_H

#define NODE_NEIGHBORS_SIZE_DEFAULT 32

#include <stdint.h>

typedef struct
{
    uint32_t val;
    size_t n_length;
    size_t n_size_max;
    void **neighbors;
} node;

node *new_node(uint32_t val);
node *get_neighbor(node *n, size_t index);
size_t add_neighbor(node *n);
size_t remove_neighbor(node *n, size_t index);
void clean_node(node *n);

#endif
