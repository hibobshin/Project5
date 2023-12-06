#include "minheap.h"

MinHeap::MinHeap() {}

bool MinHeap::empty() const {
    return heap.empty();
}

void MinHeap::insert(Vertex& vertex) {
    heap.push_back(vertex);
    std::push_heap(heap.begin(), heap.end(), MinHeapComparator());
}

Vertex MinHeap::extractMin() {
    if (empty()) {
        return Vertex{-1, 0.0f, -1, false, {}};
    }

    Vertex minVertex = heap.front();
    std::pop_heap(heap.begin(), heap.end(), MinHeapComparator());
    heap.pop_back();
    return minVertex;
}

void MinHeap::decreaseKey(Vertex& vertex, float newDistance) {
    // Update the distance of the vertex
    vertex.distance = newDistance;

    // Reorder the heap after the key has been decreased
    std::make_heap(heap.begin(), heap.end(), MinHeapComparator());
}
