// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UnionSet {
    vector<int> parent;
    vector<int> sze;

    int root(int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

public:
    UnionSet(int n) {
        int size = n + 1;
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
        sze.resize(size, 1);
    }

    void setUnion(int x, int y) {
        int rootX = root(x);
        int rootY = root(y);
        if (rootX == rootY) return;

        if (sze[rootX] > sze[rootY]) {
            sze[rootX] += sze[rootY];
            parent[rootY] = rootX;
        }
        else {
            sze[rootY] += sze[rootX];
            parent[rootX] = rootY;
        }
    }

    bool isSameSet(int x, int y) {
        return root(x) == root(y);
    }
};

class UndirectedGraph {
    vector<vector<int> > adjList;
    int nVtx;

    enum state { UNVISITED, VISITED, EXPLORED };

    bool detectCycle(int src, vector<state>& visited, int parent) {
        visited[src] = EXPLORED;

        auto& nbrList = adjList[src];
        for (int i = 0; i < nbrList.size(); ++i) {
            int curNbr = nbrList[i];
            if (curNbr != parent && visited[curNbr] == EXPLORED) {
                return true;    // cycle is there; EXP-->EXP
            }
            else if (visited[curNbr] == UNVISITED) {
                bool cycleInRem = detectCycle(curNbr, visited, src);
                if (cycleInRem) return cycleInRem;
            }
        }
        visited[src] = VISITED;
        return false;
    }


public:
    UndirectedGraph(int numVtx) {
        nVtx = numVtx + 1;
        adjList.resize(nVtx);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    bool detectCycle() {
        vector<state> visited(nVtx, UNVISITED);
        for (int curVtx = 1; curVtx <= nVtx; ++curVtx) {
            if (visited[curVtx] == UNVISITED) {
                bool ans = detectCycle(1, visited, -1);
                if (ans) return ans;
            }
        }
        return false;
    }

    bool detectCycle2() {
        queue<int> q;
        UnionSet vtxSet(nVtx);
        vector<int> parent(nVtx, -1);
        q.push(1);
        parent[1] = -2;

        while (q.empty() == false) {
            int curVtx = q.front(); q.pop();
            auto& nbrList = adjList[curVtx];
            for (int i = 0; i < nbrList.size(); ++i) {
                int curNbr = nbrList[i];
                if (parent[curVtx] != curNbr && vtxSet.isSameSet(curNbr, curVtx) == true) {
                    return true;
                }
                else if (parent[curNbr] == -1) {
                    // this means this vtx has not been visited so far
                    vtxSet.setUnion(curNbr, curVtx);
                    q.push(curNbr);
                    parent[curNbr] = curVtx;
                }

            }
        }
        return false;
    }
};

int main() {
    int nVtx, nEdges;
    cin >> nVtx >> nEdges;

    UndirectedGraph g(nVtx);

    for (int i = 0; i < nEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    bool ans = g.detectCycle2();
    cout << ans;
}