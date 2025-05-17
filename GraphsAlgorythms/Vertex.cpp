//
// Created by Wh1tEW0lf13 on 16.05.2025.
//

#include "Vertex.h"
bool _isInMST;
Vector<int> _edges;
Vector<int> _nextVertex;
Vector<int> _prevVertex;
Vector<int> _weight;

Vertex::Vertex() {
    this->_isInMST = false;
    this->_edges;
    this->_nextVertex;
    this-> _prevVertex;
    this->_weight;
}
Vertex::~Vertex() {

}

void Vertex::AddEdge(int weight) {
    _edges.Add(weight);
}

void Vertex::AddNext(int vertex, int weight) {
    _nextVertex.Add(vertex);
    _weight.Add(weight);
}
void Vertex::AddPrev(int vertex) {
    _prevVertex.Add(vertex);
}

int Vertex::GetEdge(int n) {
    return _edges.GetValue(n);
}
int Vertex::GetEdgeSizes() {
    return _edges.GetSize();
}
void Vertex::InMST() {
    _isInMST = true;
}
bool Vertex::GetInMST() {
    return _isInMST;
}

void Vertex::RemoveEdge(int index) {
    _edges.Remove(index);
}

void Vertex::ChangeWeight(int index, int weight) {
    this->_edges.ChangeValue(index, weight);
}