#include "graph.h"

Graph::Graph(int size) : size(size) 
{
    adjMatrix.resize(size, std::vector<int>(size, INF));
    for (int i = 0; i < size; ++i) 
    {
        adjMatrix[i][i] = 0;
    }
    vertices = { "Oleg", "Nikita", "Nastya", "Vanya", "Jenya" };
}

void Graph::addEdge(int v1, int v2) 
{
    adjMatrix[v1][v2] = 1;
    adjMatrix[v2][v1] = 1;
}

void Graph::floydWarshall() 
{
    for (int k = 0; k < size; ++k) 
    {
        for (int i = 0; i < size; ++i) 
        {
            for (int j = 0; j < size; ++j) 
            {
                if (adjMatrix[i][k] < INF && adjMatrix[k][j] < INF) 
                {
                    adjMatrix[i][j] = std::min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }
}

void Graph::findAllPairsWithinThreeHandshakes() 
{
    floydWarshall();
    std::cout << "Pairs of people within three handshakes:\n";
    for (int i = 0; i < size; ++i) 
    {
        for (int j = i + 1; j < size; ++j) 
        {
            if (adjMatrix[i][j] <= 3) 
            {
                std::cout << vertices[i] << " - " << vertices[j] << "\n";
            }
        }
    }
}