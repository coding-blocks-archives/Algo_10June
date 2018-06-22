// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;
class SpecialStack{
private:
    stack<int> normal;
    stack<int> special;
public:
    void push(int x){
        normal.push(x);
        if (special.empty()){
            special.push(x);
            return;
        }
        // it's confirmed that special is not empty
        if (x < special.top()){
            special.push(x);
        }
        else {
            special.push(special.top());
        }
    }
};

int main(){
       
}