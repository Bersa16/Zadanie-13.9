#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <climits>

const int INF = INT_MAX;

class Graph 
{
public:
    Graph(int size);
    void addEdge(int v1, int v2);
    void floydWarshall();
    void findAllPairsWithinThreeHandshakes();

private:
    int size;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::string> vertices;
};

#endif 