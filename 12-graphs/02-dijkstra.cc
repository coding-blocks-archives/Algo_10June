// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
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

    class Compare{
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            if (a.second < b.second) return false;
            return true;
        }
    };
    

    vector<int> dijkstraForSssp(int src) {
        // SSSP Single Source Shortest Path
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare>  minHeap;
        vector<int> dist(sze, 0);
        vector<bool> visited(sze, false);

        minHeap.push(make_pair(src, 0));

        while (minHeap.empty() == false) {
            pair<int, int> curVtxWt = minHeap.top(); minHeap.pop();
            int curVtx = curVtxWt.first;
            int distFrmSrc = curVtxWt.second;
            if (visited[curVtx] == false) {
                visited[curVtx] = true;
                dist[curVtx] = distFrmSrc;
            }
            else {
                continue;
            }

            const vector<pair<int, int> >& nbrList = adjList[curVtx];
            // const auto& nbrList = adjList[curVtx];
            for (int i = 0;  i < nbrList.size(); ++i) {
                pair<int, int> curNbrWt = nbrList[i];
                int curNbr = curNbrWt.first;
                if (visited[curNbr] == true) continue;
                int curWt = curNbrWt.second;
                int distCurNbrFrmSrc = distFrmSrc + curWt;
                minHeap.push(make_pair(curNbr, distCurNbrFrmSrc));
            }
        }
        return dist;
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


class Edge{
public:
    int src, dest, wt;
    Edge(int s, int d, int w){
        src = s;
        dest = d;
        wt = w;
    }
};

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

    bool isSameSet(int x, int y){
        return root(x) == root(y);
    }
};


bool compareEdges(const Edge& e1, const Edge& e2){
    return e1.wt < e2.wt;
}

int kruskalForMST(Graph& G){
    vector<Edge> edges;
    for(int curVtx = 1;  curVtx <= G.nVtx; ++curVtx){
        auto& nbrList = G.adjList[curVtx];
        for(int i = 0; i < nbrList.size(); ++i){
            auto curNbr = nbrList[i];
            Edge e(curVtx, curNbr.first, curNbr.second);
            edges.push_back(e);
        }
    }

    // kruskal Starts here
    UnionSet edgeSet(G.nVtx);
    sort(edges.begin(), edges.end(), compareEdges);
    int cost = 0;
    for(int i = 0; i < edges.size(); ++i){
        Edge& curEdge = edges[i];
        if (edgeSet.isSameSet(curEdge.src, curEdge.dest) == false){
            // this edge is important
            cost += curEdge.wt;
            edgeSet.setUnion(curEdge.src, curEdge.dest);
        }
    }
    return cost;
}

int main() {
    int nVtx, nEdges;
    cin >> nVtx >> nEdges;
    Graph g(nVtx);

    for (int i = 0; i < nEdges; ++i) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }

    g.print();

    // int src; cin >> src;
    // auto ans = g.dijkstraForSssp(src);
    // for(int i = 1; i < ans.size(); ++i){
    //     cout << i << " " << ans[i] << endl;
    // }

    int ans = kruskalForMST(g);
    cout << ans;
}