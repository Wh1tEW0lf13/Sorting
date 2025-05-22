#include "MST.h"
#include "../Vector.h"
#include "Vertex.h"
#include <iostream>
#include <limits>

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