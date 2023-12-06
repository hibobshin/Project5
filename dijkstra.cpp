#include "graph.h"
#include "minheap.h"
#include "dijkstra.h"

#include <iostream>
#include <iomanip>
#include <limits>

void relax(std::vector<Vertex>& graph, Vertex& u, const Edge& e, MinHeap& minHeap, int flag);

void dijkstraVariant(std::vector<Vertex>& graph, int source, int destination, int flag) {
    MinHeap minHeap;

    graph[source].distance = 0.0f;
    graph[source].predecessor = -1;

    minHeap.insert(graph[source]);

    while (!minHeap.empty()) {
        Vertex u = minHeap.extractMin();

        if (u.id == destination && flag == 1) {
            // Stop when the destination is extracted from the heap (flag == 1)
            return;
        }

        for (const Edge& e : u.adjacencyList) {
            relax(graph, u, e, minHeap, flag);
        }
    }
}

void relax(std::vector<Vertex>& graph, Vertex& u, const Edge& e, MinHeap& minHeap, int flag) {
    Vertex& v = graph[e.v];
    float newDistance = u.distance + e.weight;

    if (newDistance < v.distance) {
        v.distance = newDistance;
        v.predecessor = u.id;

        if (!v.inHeap) {
            minHeap.insert(v);

            if (flag == 1) {
                std::cout << "Insert vertex " << v.id << ", key=" << std::setw(12) << v.distance << std::endl;
            }
        } else {
            minHeap.decreaseKey(v, newDistance);

            if (flag == 1) {
                std::cout << "Decrease key of vertex " << v.id << ", from " << std::setw(12) << u.distance
                          << " to " << std::setw(12) << newDistance << std::endl;
            }
        }
    }
}

void handleFindQuery(std::vector<Vertex>& graph, int source, int destination, int flag) {
    std::cout << "Query: find " << source << " " << destination << " " << flag << std::endl;
    dijkstraVariant(graph, source, destination, flag);
}

void handleWritePathQuery(std::vector<Vertex>& graph, int s, int d) {
    std::cout << "Query: write path " << s << " " << d << std::endl;

    if (graph[d].predecessor == -1) {
        // No path computation done
        std::cout << "Error: no path computation done" << std::endl;
    } else if (s != graph[s].id || d >= static_cast<int>(graph.size()) || d < 1) {
        // Invalid source-destination pair
        std::cout << "Error: invalid source destination pair" << std::endl;
    } else if (graph[d].distance < std::numeric_limits<float>::infinity()) {
        // Shortest path is computed
        std::cout << "Shortest path: ";
        int current = d;
        while (current != -1) {
            std::cout << current << " ";
            current = graph[current].predecessor;
        }
        std::cout << std::endl << "The path weight is: " << graph[d].distance << std::endl;
    } else {
        // No path exists
        std::cout << "No s-d path exists." << std::endl;
    }
}
