// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

int cnt;
void printSubsets(int arr[], int be, int n, int decision[], int i) {
    if (be == n){
        ++cnt;
        cout << cnt << ".\t";
        outputArr(decision, i);
        cout << endl;
        return;
    }

    decision[i] = arr[be];
    printSubsets(arr, be + 1, n, decision, i + 1);
    printSubsets(arr, be + 1, n, decision, i);
}


int main() {
    int arr[100];
    int n;
    cin >> n;
    inputArr(arr, n);

    int tmp[100];
    printSubsets(arr, 0, n, tmp, 0);
}