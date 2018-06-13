// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printHello(int n){
    for(int i = 0; i < n; ++i){
        cout << i << " hello" << endl;
    }
}

void printHello2(int n){
    for(int i = 0; i < n * n; ++i){
        if (i < n){
            cout << i << " hello " << endl;
        }
    }
}


int main(){
    int n;
    cin >> n;   
}