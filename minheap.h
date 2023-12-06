#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <queue>

#include "graph.h"

struct MinHeapComparator {
    bool operator()(const Vertex& a, const Vertex& b) const {
        return a.distance > b.distance;
    }
};

class MinHeap {
public:
    MinHeap();
    bool empty() const;
    void insert(Vertex& vertex);
    Vertex extractMin();
    void decreaseKey(Vertex& vertex, float newDistance);

private:
    std::vector<Vertex> heap;
};

#endif  // MINHEAP_H
