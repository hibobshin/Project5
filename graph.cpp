#include "graph.h"
#include <fstream>
#include <algorithm>  // Add this line for the swap function

Graph::Graph() {}

void Graph::readGraph(const char* filename, bool isDirected) {
    std::ifstream file(filename);
    int n, m;
    file >> n >> m;

    vertices.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        Edge e;
        file >> e.id >> e.u >> e.v >> e.weight;

        vertices[e.u].adjacencyList.push_back(e);

        if (!isDirected) {
            std::swap(e.u, e.v);  // Use std::swap instead of swap
            vertices[e.u].adjacencyList.push_back(e);
        }
    }

    file.close();
}

const std::vector<Vertex>& Graph::getVertices() const {
    return vertices;
}
