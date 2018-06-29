// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int cnt = 0;

void printPermutations(char arr[], int be){
    if (arr[be] == '\0'){
        ++cnt;
        cout << cnt << " " <<  arr << endl;
        return;
    }

    for(int i = be; arr[i] != '\0'; ++i){
        // try placing the current char at beginning
        swap(arr[i], arr[be]); // fix the ith element at the be
        printPermutations(arr, be + 1);
        // restore the changes
        swap(arr[i], arr[   be]);
    }
}


int main(){
    char arr[100];
    cin >> arr;
    printPermutations(arr, 0);   
}