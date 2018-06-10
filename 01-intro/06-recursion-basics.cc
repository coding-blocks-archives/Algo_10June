// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int n){
    if (n <= 0) {
        return 1;   // base case
    }
    int smallFact = factorial(n - 1); 
    int ans = n * smallFact;    // recurrence relation
    return ans;
}

int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prevFib = fib(n - 1);
    int superPrev = fib(n - 2);
    return prevFib + superPrev;
}



int main(){
    // int n;
    // cin >> n;
    // int ans = factorial(n);
    // cout << ans;

    int n;
    cin >> n;
    int ans = fib(n);
    cout << ans;  
}