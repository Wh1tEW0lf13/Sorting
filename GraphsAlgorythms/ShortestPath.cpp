//
// Created by Wh1tEW0lf13 on 24.05.2025.
//

#include "ShortestPath.h"
int ShortestPath::Dijkstra(int size, Vertex* graph, int source, int destination) {
    Vector<int> dist;
    Vector<bool> visited;

    for (int i = 0; i < size; i++) {
        dist.Add(INT_MAX);
        visited.Add(false);
    }
    dist.ChangeValue(source, 0);

    for (int count = 0; count < size - 1; count++) {
        int u = -1;
        int minDist = INT_MAX;
        for (int v = 0; v < size; v++) {
            if (!visited.GetValue(v) && (u == -1 || dist.GetValue(v) < dist.GetValue(u))) {
                u = v;
            }
        }

        if (dist.GetValue(u) == INT_MAX) break; //
        visited.ChangeValue(u,true);

        if (u == destination) break; // arrived

        // Distance between two vertex
        for (int i = 0; i < graph[u].GetNeighborSizes(); i++) {
            int weight = graph[u].GetWeight(i);
            int neighbor = graph[u].GetNeighbor(i);
            if (weight > 0 && !visited.GetValue(neighbor) && dist.GetValue(u) + weight < dist.GetValue(neighbor)) {
                dist.ChangeValue(neighbor, dist.GetValue(u) + weight);
            }
        }
    }

    int result = dist.GetValue(destination);
    if (result == INT_MAX) {
        std::cout << "There is no path from " << source << " to " << destination << std::endl;
    } else {
        std::cout << "There is path from " << source << " to " << destination << ": " << result << std::endl;
    }
    return result;
}