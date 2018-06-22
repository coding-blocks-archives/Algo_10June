// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

bool compareIntInc(int a, int b){
    // shall a come before b
    if (a < b) return true;
    return false;
}

bool compareIntDec(int a, int b){
    if (a < b) return false;
    return true;
}

void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[] = {1,10 , 100 , -12, -11};    
    int n = 5;
    sort(arr, arr + 5, compareIntDec);
    outputArr(arr, 5);
}