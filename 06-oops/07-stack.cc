// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;   
    s.push(2);
    s.push(3);
    s.push(4);

    while(s.empty() == false){
        cout << s.top();
        s.pop();
    }
}