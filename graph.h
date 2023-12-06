#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Edge {
    int id, u, v;
    float weight;
};

struct Vertex {
    int id;
    float distance;
    int predecessor;
    bool inHeap;
    std::vector<Edge> adjacencyList;
};

class Graph {
public:
    Graph();
    void readGraph(const char* filename, bool isDirected);
    const std::vector<Vertex>& getVertices() const;

private:
    std::vector<Vertex> vertices;
};

#endif // GRAPH_H
