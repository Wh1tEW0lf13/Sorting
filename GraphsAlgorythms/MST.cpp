#include "MST.h"
#include "../Vector.h"
#include "Vertex.h"
#include "../SortingAlgorythms/QuickSort.h"

Vertex* MST::Prim(int size, Vertex* graph, int maxWeight) {
    int mstWeight = 0;
    Vertex* mst = new Vertex[size];

    graph[0].InMST();

    for (int i = 0; i < size - 1; i++) {
        int u = -1;
        int ver = -1;
        int minKey = maxWeight + 1;
        int edgeIndexToRemove = -1;


        for (int v = 0; v < size; v++) {
            if (graph[v].GetInMST()) {

                for (int j = 0; j < graph[v].GetEdgeSizes(); j++) {
                    int edgeWeight = graph[v].GetEdge(j);

                    if (edgeWeight > 0 && edgeWeight < minKey) {
                        for (int k = 0; k < size; k++) {
                            if (graph[k].GetEdge(j) == edgeWeight && !graph[k].GetInMST() && k != v) {
                                u = k;
                                ver = v;
                                edgeIndexToRemove = j;
                                minKey = edgeWeight;
                            }
                        }
                    }
                }
            }
        }
        mstWeight += minKey;
        graph[u].InMST();
        for (int h = 0; h < size; h++) {
            if (h == u) {
                mst[h].AddEdge(minKey);
                mst[h].AddNext(ver, minKey);
                graph[h].ChangeWeight(edgeIndexToRemove, 0);
            }
            else if (h == ver) {
                mst[h].AddEdge(minKey);
                mst[h].AddNext(u, minKey);
                graph[h].ChangeWeight(edgeIndexToRemove, 0);
            }
            else {
                mst[h].AddEdge(0);
            }
        }
    }
    for (int i = 0;i < size;++i) {
        for (int j = 0; j < mst[0].GetEdgeSizes(); ++j) {
            std::cout << mst[i].GetEdge(j)<<" ";
        }
        std::cout << std::endl;
    }

    std::cout << "Calkowita waga MST: " << mstWeight << std::endl;
    return mst;
}
struct Edge {
    int u, v, weight;
};

int find(int u, int* parent) {
    if (parent[u] != u)
        parent[u] = find(parent[u], parent);
    return parent[u];
}

void unite(int u, int v, int* parent, int* rank) {  //Connecting two vertex if cycle do not exists
    u = find(u, parent);
    v = find(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

void quickSort(Edge* edges, int low, int high) {
    if (low < high) {
        int pivot = edges[high].weight;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (edges[j].weight < pivot) {
                i++;
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }

        Edge temp = edges[i + 1];
        edges[i + 1] = edges[high];
        edges[high] = temp;

        int pi = i + 1;

        quickSort(edges, low, pi - 1);
        quickSort(edges, pi + 1, high);
    }
}

void sortEdges(Edge* edges, int edgeCount) {
    quickSort(edges, 0, edgeCount - 1);
}

Vertex* MST::Kruskal(int size, Vertex* graph, int maxWeight) {
    Vertex* mst = new Vertex[size];
    Edge* edges = new Edge[size * size]; // max liczba krawędzi
    int edgeCount = 0;

    // Zbieranie unikalnych krawędzi
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < graph[i].GetEdgeSizes(); j++) {
            int weight = graph[i].GetEdge(j);
            if (weight > 0) {
                for (int k = 0; k < size; k++) {
                    if (k != i && graph[k].GetEdge(j) == weight) {
                        if (i < k) { // uniknij duplikatu
                            edges[edgeCount++] = { i, k, weight };
                        }
                        break;
                    }
                }
            }
        }
    }
    sortEdges(edges, edgeCount);
    int* parent = new int[size];
    int* rank = new int[size];
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    std::cout<<edgeCount<<std::endl;
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u, parent) != find(v, parent)) {
            unite(u, v, parent, rank);

            mst[u].AddEdge(w);
            mst[u].AddNext(v, w);

            mst[v].AddEdge(w);
            mst[v].AddNext(u, w);

            mstWeight += w;
            for (int i = 0; i<size; i++) {
                if (i != u && i != v) {
                    mst[i].AddEdge(0);
                }
            }
        }
    }

    std::cout << "Calkowita waga MST: " << mstWeight << std::endl;

    delete[] edges;
    delete[] parent;
    delete[] rank;

    return mst;
}