// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int mysqrt(int num) {
    int be = 0;
    int en = num;
    int mid;

    while (be <= en) {
        mid = (be + en) / 2;
        if (mid * mid == num) {
            return mid;
        }
        else if (mid * mid < num) {
            be = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }
    return en;
}

int main() {
    int num;
    cin >> num;
    double ans = mysqrt(num);
    cout << ans;
}