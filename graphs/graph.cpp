#include <vector>
#include <math.h>
#include <cstdio>

class Node 
{
public:
    unsigned int value;
    bool visited;
    float distance;

    std::vector<Node*> neighbours;

    Node(unsigned int value) {
        this->value = value;
        this->visited = false;
        this->distance = INFINITY;
    }
};

class Queue {
public:
    std::vector<Node*> items;

    Queue() {
    }

    void enqueue(Node* node) {
        items.push_back(node);
    }

    Node* dequeue() {
        Node* r = this->items.front(); // to return
        this->items.erase(this->items.begin());
        return r;
    }

};   

class Graph
{
public:
    int n;
    std::vector<Node*> nodes;

    Graph(std::vector<Node*> nodes) {
        this->nodes = nodes;
    }

    void BFS() 
    {
        Node *start = this->nodes.at(0);
        Queue Q = Queue();
        Q.enqueue(start);

        while(Q.items.size() > 0) {
            Node *v = Q.dequeue();
            v->visited = true;

            printf("Node %d\n", v->value);
            

            for (Node* n : v->neighbours) {
                if (!n->visited) {
                    printf("  Enqueueing Node %d\n", n->value);
                    n->visited = true; // Mark the neighbor as visited
                    Q.enqueue(n);
                } else {
                    printf("  Node %d already visited\n", n->value);
                }
            }
          
        }
    }

    // find anything
    void DFS(Node * start = NULL) {
        if(start == NULL) start = this->nodes.at(0);

        start->visited = true;
        for(Node * neighbor : start->neighbours) {
            printf("DFS: Node %d\n", neighbor->value);
            if(!neighbor->visited)
                DFS(neighbor);
        }
    }


};

int main() {
    
    Node node1 = Node(1);
    Node node2 = Node(2);
    Node node3 = Node(3);
    Node node4 = Node(4);

    std::vector<Node*> neighbours1 = {&node3, &node2};
    std::vector<Node*> neighbours2 = {&node1, &node4};
    std::vector<Node*> neighbours3 = {&node1, &node4, &node2};
    std::vector<Node*> neighbours4 = {&node1};

    node1.neighbours = neighbours1;
    node2.neighbours = neighbours2;
    node3.neighbours = neighbours3;
    node4.neighbours = neighbours4;

    std::vector<Node*> nodes = {&node1, &node2, &node3, &node4};
    Graph G = Graph(nodes);

    G.BFS();

    for(int i = 0; i < G.n; i++) {
        G.nodes[i]->visited = false;
    }

    G.DFS();

}








