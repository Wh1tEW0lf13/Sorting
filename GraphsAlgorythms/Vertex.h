//
// Created by Wh1tEW0lf13 on 16.05.2025.
//

#ifndef VERTEX_H
#define VERTEX_H
#include "../Vector.h"


class Vertex {
    public:
    Vertex();
    ~Vertex();
    void AddEdge(int weight);
    void AddNext(int vertex, int weight);
    void AddPrev(int vertex);
    int GetEdge(int n);
    int GetEdgeSizes();
    int GetWeight(int index);
    void RemoveEdge(int index);
    void InMST();
    bool GetInMST();
    void ChangeWeight(int index, int weight);
    int GetNeighbor(int index);
    int GetPrevNeighbor(int index);
    int GetNeighborSizes();
    void ChangeMSTWeight(int weight);
    int GetMSTWeight();
private:
    Vector<int> _edges;  //It creates in incident matrix
    Vector<int> _nextVertex;
    Vector<int> _prevVertex;
    Vector<int> _weight;
    bool _isInMST;
    int _mstWeight;
};



#endif //VERTEX_H
