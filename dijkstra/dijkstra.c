#include "dijkstra.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    node *n1 = new_node(1);
    node *n2 = new_node(2);
    node *n3 = new_node(3);
    node *n4 = new_node(4);
    node *n5 = new_node(5);
    node *n6 = new_node(6);
    node *n7 = new_node(7);

    n1->neighbors[0] = (void *)n2;
    n1->neighbors[1] = (void *)n3;

    printf("%d", get_neighbor(n1, 0)->val);

    clean_node(n1);

    return 0;
}
