// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;
void vacate(stack<int>& from, stack<int>& to, int n){
    for(int i = 0; i < n; ++i){
        to.push(from.top()); from.pop();
    }
}

void reverseStack1(stack<int>& s){
    stack<int> tmp;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        int cur = s.top(); s.pop();
        vacate(s, tmp, n - i - 1);
        s.push(cur);
        vacate(tmp, s, n - i - 1);
    }
}


void insertAtBottom(stack<int>& s, int elementToInsert){
    if (s.empty()) {
        s.push(elementToInsert); 
        return;
    }

    int cur = s.top(); s.pop();
    insertAtBottom(s, elementToInsert);
    s.push(cur);
}

void reverseStack0(stack<int>& s){
    if (s.empty()) return;
    int cur = s.top(); s.pop();
    reverseStack0(s);
    insertAtBottom(s, cur);
}

int main() {
    stack<int> s;

    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        s.push(x);
    }

    reverseStack0(s);

    while (s.empty() == false) {cout << s.top(); s.pop();}
}