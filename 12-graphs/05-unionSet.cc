// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
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

    bool isSameSet(int x, int y){
        return root(x) == root(y);
    }
};

int main() {
    UnionSet s(10);
    cout << s.isSameSet(4, 8) << endl;
    s.setUnion(4, 8);
    cout << s.isSameSet(4, 8) << endl;
    cout << s.isSameSet(8, 9) << endl;
    s.setUnion(8, 9);
    cout << s.isSameSet(8, 9) << endl;
    
    cout << s.isSameSet(8, 5) << endl;
    s.setUnion(4, 5);
    cout << s.isSameSet(8, 5) << endl;

}