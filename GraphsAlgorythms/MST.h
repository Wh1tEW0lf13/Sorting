//
// Created by Wh1tEW0lf13 on 17.05.2025.
//

#ifndef MST_H
#define MST_H
#include "Vertex.h"


class MST {
public:
    static Vertex* PrimMatrix(int size, Vertex* graph);
    static Vertex* PrimList(int size, Vertex* graph);
    static Vertex* KruskalMatrix(int size, Vertex* graph, int maxWeight);
    static Vertex* KruskalList(int size, Vertex* graph, int maxWeight);
};



#endif //MST_H
