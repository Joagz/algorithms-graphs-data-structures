
#ifndef HEAP_H
#define HEAP_H
// min oriented heap implementation

#include <stdint.h>

struct heap
{
    size_t size;
    size_t length;
    uint32_t *nodes;
};

// Allocate size for node_n elements of uint32_t
struct heap *heapalloc(size_t node_n);
// Delete element at position index
uint32_t heapdelete(size_t index, struct heap *H);
// Insert a new element into the heap
void heapinsert(uint32_t node, struct heap *H);
// Get the root of the heap
uint32_t heaproot(struct heap *H);
// Get the root of the heap and delete it
uint32_t heapextractroot(struct heap *H);
#endif