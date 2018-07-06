// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;


bool compareFun(int a, int b) {
    if (a < b) { return false; }
    return true;
    // a shall come after b if its a min heap because elements are popped from the end
}

class Elephant {
public:
    bool operator()(int a, int b) {
        if (a < b) { return false; }
        return true;
    }
};



int main() {
    // priority_queue<int, vector<int>, bool (*)(int a, int b)> pq;
    // priority_queue<int, vector<int>, compareFun> pq;

    priority_queue < int, vector<int>, Elephant> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top();
}