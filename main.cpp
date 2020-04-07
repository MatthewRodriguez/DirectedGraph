#include "DirectedGraph.h"

int main(int argc, const char * argv[]) {
    vector<Node*> v;
    DirectedGraph g;
    Node *n = nullptr;
    g.createRandomDAGIter(1000);
    cout << "DiretedGraph";
    g.printNodes();
    cout << endl;
    g.printU();
    v = g.Kahns();
    cout << "Kahns: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i]->info << " ";
    cout << endl;
    v = g.mDFS();
    cout << "mDFS: ";
    while (!v.empty()){
        n = v.back();
        cout << n->info << " ";
        v.pop_back();
    }
    cout << endl;
    return 0;
}
