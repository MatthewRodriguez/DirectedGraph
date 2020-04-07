//
//  DirectedGraph.cpp
//  DirectedGraph
//
//  Created by Matt Rodriguez on 3/31/20.
//  Copyright © 2020 Matthew Rodriguez. All rights reserved.
//

#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(){
    nodes.clear();
}

void DirectedGraph::addNode(int val){
    Node *n = new Node(val);
    if (nodes.empty())
        nodes.push_back(n);
    else{
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i]->info == val)
                return;
        nodes.push_back(n);
    }
}

void DirectedGraph::addDirectedEdge(Node *first, Node *second){
    if (first->list.empty() && (first->info != second->info)){
        first->list.push_back(second);
        second->degree += 1;
    }
    else if(first->info == second->info){
        return;
    }
    else{
        for (int i = 0; i < first->list.size(); i++){
            if (first->list[i]->info == second->info)
                return;
        }
        first->list.push_back(second);
        second->degree += 1;
    }
}

void DirectedGraph::removeDirectedEdge(Node *first, Node *second){
    if (first->list.empty())
        return;
    for (int i = 0; i < first->list.size(); i++){
        if (first->list[i]->info == second->info)
            first->list.erase(first->list.begin()+i);
    }
}

unordered_set<Node*> DirectedGraph::getAllNodes(){
    unordered_set<Node*> s;
    for (int i = 0; i < nodes.size(); i++)
        s.insert(nodes[i]);
    return s;
}

void DirectedGraph::createRandomDAGIter(int n){
    int a, b;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, (n));
    for (int i = 0; i < n; i++){
        addNode(dist(mt));
    }
    for (int i = 0; i < nodes.size(); i++){
        if(nodes.size() > 1){
            a = dist(mt) % nodes.size();
            b = dist(mt) % nodes.size();
            addDirectedEdge(nodes[a], nodes[b]);
        }
    }
}

void DirectedGraph::printNodes(){
    cout << " { ";
    for (int i = 0; i < nodes.size(); i++)
        cout << nodes[i]->info << " ";
    cout << " }" << endl;
}

void DirectedGraph::printU(){
    for (int i = 0; i < nodes.size(); i++){
        cout << nodes[i]->info << ": ";
        for (int j = 0; j < nodes[i]->list.size(); j++)
            cout << nodes[i]->list[j]->info << " ";
        cout << endl;
    }
    cout << endl;
}

void DirectedGraph::resetVisit(){
    for (int i = 0; i < nodes.size(); i++)
        nodes[i]->visit = false;
}

vector<Node*> DirectedGraph::Kahns(){
    vector<Node*> q, tSort;
    Node *n;
    
    for (int i = 0; i < nodes.size(); i++){
        if (nodes[i]->degree == 0)
            q.push_back(nodes[i]);
    }
    
    while (!q.empty()){
        n = q.front();
        q.erase(q.begin());
        tSort.push_back(n);
        for (int j = 0; j < n->list.size(); j++){
            n->list[j]->degree -= 1;
            if (n->list[j]->degree == 0)
                q.push_back(n->list[j]);
        }
    }
    
    return tSort;
}

vector<Node*> DirectedGraph::mDFS(){
    vector<Node*> v, path;
    Node *n;
    for (int i = 0; i < nodes.size(); i++){
        if (!nodes[i]->visit){
            nodes[i]->visit = true;
            v.push_back(nodes[i]);
            while (!v.empty()){
                n = v.back();
                v.pop_back();
                path.push_back(n);
                for (int j = 0; j < n->list.size(); j++){
                    if (!n->list[j]->visit){
                        n->list[j]->visit = true;
                        v.push_back(n->list[j]);
                    }
                }
            }
        }
    }
    resetVisit();
    return path;
}
