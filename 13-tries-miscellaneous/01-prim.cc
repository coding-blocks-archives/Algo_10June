// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<pair<int, int> > > adjList;
    int sze;
    int nVtx;
    Graph(int numVtx) {
        nVtx = numVtx;
        sze = nVtx + 1;
        adjList.resize(sze);
    }

    void addEdge(int src, int dest, int wt) {
        adjList[src].push_back(make_pair(dest, wt));
        adjList[dest].push_back(make_pair(src, wt));
    }

    class Compare {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second < b.second) return false;
            return true;
        }
    };

    int primMST() {
        typedef pair<int, int> Edge;
        
        int src = 1;
        priority_queue<Edge, vector<Edge>, Compare> minHeap;
        vector<bool> visited(sze, false);

        minHeap.push(make_pair(src, 0));
        int cost = 0;

        while (minHeap.empty() == false) {
            Edge curEdge = minHeap.top(); minHeap.pop();
            int curVtx = curEdge.first;
            int curWt = curEdge.second;
            if (visited[curVtx] == false) {
                // I have not considered/visited this vertex
                visited[curVtx] = true;
                cost += curWt;
            }
            else {
                continue;
            }

            const vector<Edge>& nbrList = adjList[curVtx];
            for(int i = 0; i < nbrList.size(); ++i){
                const Edge& nbrEdge = nbrList[i];
                int nbrVtx = nbrEdge.first;
                int nbrWt = nbrEdge.second;
                if (visited[nbrVtx] == false){
                    minHeap.push(nbrEdge);
                }
            }
        }
        return cost;
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

int main(){
    int nVtx, nEdges;
    cin >> nVtx >> nEdges;
    Graph g(nVtx);

    for (int i = 0; i < nEdges; ++i) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }

    g.print();
    int ans = g.primMST();
    cout << ans;
}