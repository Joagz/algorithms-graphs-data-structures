#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct heap
{
    uint32_t *nodes;
    size_t size;
    size_t length;
};

void exch(uint32_t *arr, size_t a, size_t b)
{
    uint32_t temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

struct heap *heapalloc(size_t node_n)
{
    struct heap *H = (struct heap *)malloc(sizeof(struct heap));
    H->nodes = (uint32_t *)malloc(sizeof(uint32_t) * (node_n + 1)); // Allocate node_n + 1 elements

    for (int i = 0; i <= node_n; i++)
    {
        H->nodes[i] = 0x00;
    }

    H->size = node_n + 1;
    H->length = 0;
    return H;
}

uint32_t heaproot(struct heap *H)
{
    if (H->length == 0)
        return 0x00;

    return H->nodes[1];
}

void heapswim(size_t index, struct heap *H)
{
    if (index > H->length || index == 1)
        return;

    uint32_t cur = H->nodes[index];
    uint32_t parent = H->nodes[index / 2];

    while (index > 1 && parent > cur)
    {
        exch(H->nodes, index, index / 2);
        index = index / 2;
        cur = H->nodes[index];
        parent = H->nodes[index / 2];
    }
}

size_t leftchild(size_t index) { return 2 * index; }

size_t rightchild(size_t index) { return 2 * index + 1; }

void heapsink(size_t index, struct heap *H)
{
    if (index > H->length)
        return;

    uint32_t cur = H->nodes[index];
    size_t lc, rc;

    while (index <= H->length)
    {
        lc = leftchild(index);
        rc = rightchild(index);

        if (lc <= H->length && H->nodes[lc] < cur)
        {
            if (rc <= H->length && H->nodes[rc] < H->nodes[lc])
            {
                exch(H->nodes, index, rc);
                index = rc;
            }
            else
            {
                exch(H->nodes, index, lc);
                index = lc;
            }
        }
        else if (rc <= H->length && H->nodes[rc] < cur)
        {
            exch(H->nodes, index, rc);
            index = rc;
        }
        else
        {
            break;
        }
    }
}

void heapinsert(uint32_t node, struct heap *H)
{
    if (H->length >= H->size - 1)
    {
        H->nodes = (uint32_t *)realloc(H->nodes, sizeof(uint32_t) * (H->size * 2));
        H->size = H->size * 2;
    }

    H->length++;
    H->nodes[H->length] = node;
    heapswim(H->length, H);
}

void heapdelete(size_t index, struct heap *H)
{
    if (index > H->length || H->length == 0)
        return;

    exch(H->nodes, index, H->length);
    H->length--;
    heapsink(index, H);
}

#ifdef DEBUG
// debbuging
int main()
{
    struct heap *H = heapalloc(10);

    heapinsert(1, H);
    heapinsert(5, H);
    heapinsert(8, H);
    heapinsert(2, H);
    heapinsert(10, H);
    heapinsert(15, H);
    heapinsert(13, H);
    heapinsert(18, H);

    for (int i = 0; i <= H->length; i++)
    {
        printf("%d ", H->nodes[i]);
    }
    printf("\n");

    heapinsert(9, H);

    for (int i = 0; i <= H->length; i++)
    {
        printf("%d ", H->nodes[i]);
    }
    printf("\n");
    heapdelete(1, H);

    for (int i = 0; i <= H->length; i++)
    {
        printf("%d ", H->nodes[i]);
    }
    printf("\n");
    heapdelete(1, H);

    for (int i = 0; i <= H->length; i++)
    {
        printf("%d ", H->nodes[i]);
    }
    printf("\n");
    heapdelete(1, H);

    for (int i = 0; i <= H->length; i++)
    {
        printf("%d ", H->nodes[i]);
    }
    printf("\n");
    heapdelete(1, H);

    for (int i = 0; i <= H->length; i++)
    {
        printf("%d ", H->nodes[i]);
    }

    printf("\n");

    free(H->nodes);
    free(H);

    return 0;
}
#endif