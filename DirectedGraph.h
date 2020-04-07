//
//  DirectedGraph.h
//  DirectedGraph
//
//  Created by Matt Rodriguez on 3/31/20.
//  Copyright © 2020 Matthew Rodriguez. All rights reserved.
//

#ifndef DirectedGraph_h
#define DirectedGraph_h
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Replits if not MATT you will fail.
*/
struct Node{
    int info;
    int degree;
    bool visit;
    //unordered_map<Node*, int> list;
    vector<Node*> list;
    Node(int i, int d = 0, bool v = false) : info(i), degree(d), visit(v) {}
};

class DirectedGraph{
    vector<Node*> nodes;
public:
    DirectedGraph();
    void addNode(int val);
    void addDirectedEdge(Node *first, Node *second);
    void removeDirectedEdge(Node *first, Node *second);
    unordered_set<Node*> getAllNodes();
    vector<Node*> Kahns();
    vector<Node*> mDFS();
    void createRandomDAGIter(int n);
    void resetVisit();
    void printNodes();
    void printU();
};
#endif /* DirectedGraph_h */
