// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Graph {
    vector<vector<pair<int, int> > > adjList;
    int sze;
    int nVtx;
public:
    Graph(int numVtx) {
        nVtx = numVtx;
        sze = nVtx + 1;
        adjList.resize(sze);
    }

    void addEdge(int src, int dest, int wt) {
        adjList[src].push_back(make_pair(dest, wt));
        adjList[dest].push_back(make_pair(src, wt));
    }

    ???? dijkstraForSssp(int src){
        
    }

    void print() {
        cout << "GRAPH BEGINS--------\n";
        for (int curVtx = 1; curVtx < sze; ++curVtx) {
            const vector<pair<int, int> >& nbrList = adjList[curVtx];
            cout << curVtx << ": ";
            for (int i = 0; i < nbrList.size(); ++i) {
                pair<int, int> curNbr = nbrList[i];
                cout << curNbr.first << "(" << curNbr.second << ") ";
            }
            cout << endl;
        }
        cout << "GRAPH ENDS--------\n";
    }
};

int main() {
    int nVtx, nEdges;
    cin >> nVtx >> nEdges;
    Graph g(nVtx);

    for(int i = 0; i < nEdges; ++i){
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }

    g.print();
}