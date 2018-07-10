// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {
    vector<vector<int> > adjList;
    int nVtx;

    enum state { UNVISITED, VISITED, EXPLORED };

    bool detectCycle(int src, vector<state>& visited) {
        visited[src] = EXPLORED;

        auto& nbrList = adjList[src];
        for (int i = 0; i < nbrList.size(); ++i) {
            int curNbr = nbrList[i];
            if (visited[curNbr] == EXPLORED) {
                return true;    // cycle is there; EXP-->EXP
            }
            else if (visited[curNbr] == UNVISITED) {
                bool cycleInRem = detectCycle(curNbr, visited);
                if (cycleInRem) return cycleInRem;
            }
        }
        visited[src] = VISITED;
        return false;
    }

public:
    DirectedGraph(int numVtx) {
        nVtx = numVtx + 1;
        adjList.resize(nVtx);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    bool detectCycle() {
        vector<state> visited(nVtx, UNVISITED);
        for (int curVtx = 1; curVtx <= nVtx; ++curVtx) {
            if (visited[curVtx] == UNVISITED) {
                bool ans = detectCycle(1, visited);
                if (ans) return ans;
            }
        }
        return false;
    }
};





int main() {
    int nVtx, nEdges; 
    cin >> nVtx >> nEdges;
    DirectedGraph g(nVtx);

    for (int i = 0; i < nEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    bool ans = g.detectCycle();
    cout << ans;
}