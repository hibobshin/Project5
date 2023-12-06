#include <iostream>
#include "graph.h"
#include "minheap.h"
#include "dijkstra.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <graph> <direction>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    const std::string direction = argv[2];
    bool isDirected = (direction == "directed");

    Graph graph;
    graph.readGraph(filename, isDirected);

    std::vector<Vertex> vertices = graph.getVertices();

    if (vertices.size() >= 2) {
        int sourceVertex = 1;
        int destinationVertex = 2;

        int queryFlag = 1;
        handleFindQuery(vertices, sourceVertex, destinationVertex, queryFlag);
    }

    return 0;
}
