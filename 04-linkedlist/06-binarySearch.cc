// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[100], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int binarySearch(int arr[], int n, int x) {
    int be = 0;
    int en = n - 1;
    while (be <= en) {
        int mid = (be + en) / 2;
        if (arr[mid] == x ) {
            return mid;
        }
        else if (arr[mid] > x) {
            en = mid - 1;
        }
        else {
            be = mid + 1;
        }
    }
    return -1;
}




int main() {
    int arr[100];
    int n; cin >> n;
    int x ; cin >> x;
    inputArr(arr, n);
    int ans = binarySearch(arr, n, x);
    cout << ans;
}