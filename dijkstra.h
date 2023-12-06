#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

#include "graph.h"
#include "minheap.h"

void dijkstraVariant(std::vector<Vertex>& graph, int source, int destination, int flag);
void handleFindQuery(std::vector<Vertex>& graph, int source, int destination, int flag);
void handleWritePathQuery(std::vector<Vertex>& graph, int s, int d);

#endif 
