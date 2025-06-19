//
// Created by Wh1tEW0lf13 on 24.05.2025.
//

#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H
#include "Vertex.h"


class ShortestPath {
public:
    static void DijkstraList(int size, Vertex* graph,int source, int destination, Vector<int>* sp);
    static void DijkstraMatrix(int size, Vertex* graph,int source, int destination, Vector<int>* sp);
    static void BellmanFordList(int size, Vertex* graph,int source, int destination, Vector<int>* sp);
    static void BellmanFordMatrix(int size, Vertex* graph,int source, int destination, Vector<int>* sp);
};



#endif //SHORTESTPATH_H
