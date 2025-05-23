//
// Created by Wh1tEW0lf13 on 17.05.2025.
//

#ifndef MST_H
#define MST_H
#include "Vertex.h"


class MST {
public:
    static Vertex* Prim(int size, Vertex* graph, int maxWeight);
    static Vertex* Kruskal(int size, Vertex* graph, int maxWeight);
};



#endif //MST_H
