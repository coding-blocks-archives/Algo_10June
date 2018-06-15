// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void getGrayCode(int n, int arr[], int& i) {
    // pushes all the gray codes of n bits into the array and adjusts the
    // value of i such that new code can be placed at that index
    /*if (n == 0){
        arr[i] = 0;
        i++;
        return;
    }*/
    if (n == 1){
        arr[i] = 0; ++i;
        arr[i] = 1; ++i;
        return ;
    }

    getGrayCode(n - 1, arr, i);
    for (int j = i - 1; j >= 0; --j) {
        int cur = arr[j];
        cur = cur | (1 << (n - 1));
        arr[i] = cur;
        ++i;
    }
}


int main() {
    int n;
    cin >> n;
    int ans[100];
    int i = 0;
    getGrayCode(n, ans, i);

    for (int j = 0; j < i; ++j) {
        cout << ans[j] << endl;
    }
}