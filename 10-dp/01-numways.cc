// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

int numWays(int n, int memoPad[]) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    if (memoPad[n] != -1) {return memoPad[n];}

    // Now I am sure that I have atleast 2 stairs

    int oneStep = numWays(n - 1, memoPad);
    int twoStep = numWays(n - 2, memoPad);
    memoPad[n] = oneStep + twoStep;
    return memoPad[n];
}

int numWaysDP(int n) {
    int* dp = new int[n + 1];
    fill(dp, dp + n + 2, -1);

    dp[0] = 1;
    dp[1] = 1;
    for (int stairNo = 2; stairNo <= n; ++stairNo) {
        dp[stairNo] = dp[stairNo - 1]  + dp[stairNo - 2];
    }

    int ans = dp[n];
    delete [] dp;
    return ans;
}

int main() {
    int nstairs;
    cin >> nstairs;

    // int* memoPad = new int[nstairs + 1];
    // for (int i = 0; i <= nstairs; ++i) memoPad[i] = -1;
    // int ans = numWays(nstairs, memoPad);
    
    int ans = numWaysDP(nstairs);
    cout << ans;
}