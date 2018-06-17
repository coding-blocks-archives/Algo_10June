// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x) cout << (#x) << "\t:" << x << endl

int* foo(){
    int* x = new int;
    int y = 10;
    delete x;
    return x;
}

int main(){
    auto ans = foo();
    print(ans);
    delete ans;

    int * x = new int[100];
    delete [] x;

    // loop(); // function that runs for a long time
}