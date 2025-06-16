//
// Created by Wh1tEW0lf13 on 24.05.2025.
//

#include "ShortestPath.h"

void ShortestPath::DijkstraList(int size, Vertex* graph, int source, int destination, Vector<int>* sp) {
    Vector<int> dist;
    Vector<bool> visited;
    Vector<int> prev;

    for (int i = 0; i < size; i++) {
        dist.Add(INT_MAX);
        visited.Add(false);
        prev.Add(-1);
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

        if (dist.GetValue(u) == INT_MAX) break;
        visited.ChangeValue(u, true);

        if (u == destination) break;

        for (int i = 0; i < graph[u].GetNeighborSizes(); i++) {
            int weight = graph[u].GetWeight(i);
            int neighbor = graph[u].GetNeighbor(i);
            if (weight > 0 && !visited.GetValue(neighbor) && dist.GetValue(u) + weight < dist.GetValue(neighbor)) {
                dist.ChangeValue(neighbor, dist.GetValue(u) + weight);
                prev.ChangeValue(neighbor, u);
            }
        }
    }

    int result = dist.GetValue(destination);
    graph[destination].ChangeDestinationValue(result);
    if (result == INT_MAX) {
        std::cout << "There is no path from " << source << " to " << destination << std::endl;
    } else {

        for (int at = destination; at != -1; at = prev.GetValue(at)) {
            sp->Add(at);
        }
        sp->Add(result);
    }
}
void ShortestPath::DijkstraMatrix(int size, Vertex* graph, int source, int destination, Vector<int>* sp) {
    Vector<int> dist;
    Vector<bool> visited;
    Vector<int> prev;

    for (int i = 0; i < size; i++) {
        dist.Add(INT_MAX);
        visited.Add(false);
        prev.Add(-1);
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

        if (dist.GetValue(u) == INT_MAX) break;
        visited.ChangeValue(u, true);

        if (u == destination) break;
        /*for (int i = 0; i < graph[u].GetNeighborSizes(); i++) {
            int weight = graph[u].GetWeight(i);
            int neighbor = graph[u].GetNeighbor(i);
            if (weight > 0 && !visited.GetValue(neighbor) && dist.GetValue(u) + weight < dist.GetValue(neighbor)) {
                dist.ChangeValue(neighbor, dist.GetValue(u) + weight);
                prev.ChangeValue(neighbor, u);
            }
        }*/
        for (int i = 0; i < graph[u].GetEdgeSizes(); i++) {
            if (graph[u].GetEdge(i)>0) {
                int weight = graph[u].GetEdge(i);
                int neighbor = -1;
                for (int j = 0; j < size; j++) {
                    if (j!=u && graph[j].GetEdge(i) == -weight) {
                        neighbor = j;
                    }
                }
                if (weight > 0 && !visited.GetValue(neighbor) && dist.GetValue(u) + weight < dist.GetValue(neighbor)) {
                    dist.ChangeValue(neighbor, dist.GetValue(u) + weight);
                    prev.ChangeValue(neighbor, u);
                }
            }
        }
    }

    int result = dist.GetValue(destination);
    graph[destination].ChangeDestinationValue(result);
    if (result == INT_MAX) {
        std::cout << "There is no path from " << source << " to " << destination << std::endl;
    } else {

        for (int at = destination; at != -1; at = prev.GetValue(at)) {
            sp->Add(at);
        }
        sp->Add(result);
    }
}

void ShortestPath::BellmanFordList(int size, Vertex* graph, int source, int destination, Vector<int>* sp) {
    Vector<int> dist;
    Vector<int> prev;

    for (int i = 0; i < size; i++) {
        dist.Add(INT_MAX);
        prev.Add(-1);
    }
    dist.ChangeValue(source, 0);

    // Relaxation
    for (int i = 0; i < size - 1; i++) {
        for (int u = 0; u < size; u++) {
            for (int j = 0; j < graph[u].GetNeighborSizes(); j++) {
                int v = graph[u].GetNeighbor(j);
                int weight = graph[u].GetWeight(j);

                if (dist.GetValue(u) != INT_MAX && dist.GetValue(u) + weight < dist.GetValue(v)) {
                    dist.ChangeValue(v, dist.GetValue(u) + weight);
                    prev.ChangeValue(v, u);
                }
            }
        }
    }

    // Checking for negative weight cycle
    for (int u = 0; u < size; u++) {
        for (int j = 0; j < graph[u].GetNeighborSizes(); j++) {
            int v = graph[u].GetNeighbor(j);
            int weight = graph[u].GetWeight(j);

            if (dist.GetValue(u) != INT_MAX && dist.GetValue(u) + weight < dist.GetValue(v)) {
                std::cout << "Graph contains a negative weight cycle" << std::endl;
            }
        }
    }
    int result = dist.GetValue(destination);
    if (result == INT_MAX) {
        std::cout << "There is no path from " << source << " to " << destination << std::endl;
    } else {
        for (int at = destination; at != -1; at = prev.GetValue(at)) {
            sp->Add(at);
        }
        sp->Add(result);
    }
}
void ShortestPath::BellmanFordMatrix(int size, Vertex* graph, int source, int destination, Vector<int>* sp) {
    Vector<int> dist;
    Vector<int> prev;

    for (int i = 0; i < size; i++) {
        dist.Add(INT_MAX);
        prev.Add(-1);
    }
    dist.ChangeValue(source, 0);

    // Relaxation
    for (int i = 0; i < size - 1; i++) {
        for (int u = 0; u < size; u++) {
            for (int j = 0; j < graph[u].GetEdgeSizes(); j++) {
                if (graph[u].GetEdge(j)>0) {
                    int weight = graph[u].GetEdge(j);
                    int v = -1;
                    for (int h = 0; h < size; h++) {
                        if (graph[h].GetEdge(j) == -weight && h != u) {
                            v = h;
                        }
                    }
                    if (dist.GetValue(u) != INT_MAX && dist.GetValue(u) + weight < dist.GetValue(v)) {
                        dist.ChangeValue(v, dist.GetValue(u) + weight);
                        prev.ChangeValue(v, u);
                    }
                }
            }
        }
    }

    // Checking for negative weight cycle
    for (int u = 0; u < size; u++) {
        for (int j = 0; j < graph[u].GetEdgeSizes(); j++) {
            if (graph[u].GetEdge(j)>0) {
                int v = -1;
                int weight = graph[u].GetEdge(j);
                for (int h = 0; h < size; h++) {
                    if (graph[h].GetEdge(j) == -weight && h != u) {
                        v = h;
                    }
                }
                if (dist.GetValue(u) != INT_MAX && dist.GetValue(u) + weight < dist.GetValue(v)) {
                    std::cout << "Graph contains a negative weight cycle" << std::endl;
                }
            }

        }
    }
    int result = dist.GetValue(destination);
    if (result == INT_MAX) {
        std::cout << "There is no path from " << source << " to " << destination << std::endl;
    } else {
        for (int at = destination; at != -1; at = prev.GetValue(at)) {
            sp->Add(at);
        }
        sp->Add(result);
    }
}