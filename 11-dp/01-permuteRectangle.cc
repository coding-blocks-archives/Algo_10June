// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
#include <iomanip>
using namespace std;
void inputMat(int mat[][100], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}
void outputMat(int mat[][100], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << setw(4) << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

int histogramArea(int arr[], int n) {
    typedef pair<int, int> ii;
    stack<pair<int, int> > s;
    int best = 0;

    for (int i = 0; i <= n; ++i) {
        int y = i;
        int x = i;
        int cur = i == n ? -1 : arr[i];
        while (s.empty() == false && s.top().first >= cur) {
            ii previous = s.top(); s.pop();
            int height = previous.first;
            x = previous.second;
            int curArea = height * (y - x);
            best = max(best, curArea);
        }
        s.push(make_pair(cur, x));
    }
    return best;
}

int computeMaxAreaRect(int grid[][100], int m, int n) {
    int lenLargestRec[100][100];
    int bestArea = 0;
    int curRow[100];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) {
                lenLargestRec[i][j] = grid[i][j];
            }
            else {
                lenLargestRec[i][j] = grid[i][j] == 1 ? lenLargestRec[i - 1][j] + grid[i][j] : 0;
            }
            curRow[j] = lenLargestRec[i][j];
        }
        sort(curRow, curRow + n);
        int curArea = histogramArea(curRow, n);
        bestArea = max(curArea, bestArea);
    }
    return bestArea;
}

int maxAreaSquare(int grid[][100], int m, int n) {
    int bestArea = 0;
    int curArea = 0;
    int dp[100][100];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 or j == 0) {
                dp[i][j] = grid[i][j];
            }
            else {
                curArea = 0;
                if (grid[i][j] == 1) {
                    curArea = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                dp[i][j] = curArea;
            }
            bestArea = max(curArea, bestArea);
        }
    }
    return bestArea;
}

int knapSack(int wt[], int val[], int n, int maxCapacity) {
    int dp[100][100];
    int bestProfit = 0;

    for (int capacity = 0; capacity <= maxCapacity; ++capacity) {
        dp[0][capacity] = capacity >= wt[0] ? val[0] : 0;
    }

    for (int item = 1; item < n; ++item) {
        int curItemWt = wt[item];
        int curItemVal = val[item];
        for (int capacity = 0; capacity <= maxCapacity; ++capacity) {
            int curProfitInc = 0;
            if (capacity >= curItemWt) {
                // include
                int remCapacity = capacity - curItemWt;
                curProfitInc = curItemVal + dp[item - 1][remCapacity];
            }
            // exclude
            int curProfitExc = dp[item - 1][capacity];
            dp[item][capacity] = max(curProfitInc, curProfitExc);
        }
    }
    return dp[n - 1][maxCapacity];
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int wineProblem(int price[], int n) {
    int dp[100][100] = {};

    for (int len = 1; len <= n; ++len) {
        int year = n - len + 1;
        int windowStart = 0;
        int windowMaxStart = n - len;
        while (windowStart <= windowMaxStart) {
            int windowEnd = windowStart + len - 1;
            if (windowStart == 0 && windowEnd == 0) {
                dp[windowStart][windowEnd] = year * price[windowStart];
                ++windowStart;
                continue;
            }
            dp[windowStart][windowEnd] =
                max(
                    year * price[windowStart] + dp[windowStart + 1][windowEnd],
                    year * price[windowEnd] + dp[windowStart][windowEnd - 1]
                );
            ++windowStart;
        }
    }
    outputMat(dp, n, n);
    return dp[0][n - 1];
}
int main() {
    // int grid[100][100];
    // int n, m;
    // cin >> m >> n;
    // inputMat(grid, m, n);
    // int ans = computeMaxAreaRect(grid, m, n);
    // int ans = maxAreaSquare(grid, m, n);
    // cout << ans << endl;

    // int val[90] = {};
    // int wt[90] = {};
    // int n; cin >> n;
    // inputArr(val, n);
    // inputArr(wt, n);
    // int maxCapacity; cin >> maxCapacity;
    // int ans = knapSack(wt, val, n, maxCapacity);
    // cout << ans;

    int price[100];
    int n; cin >> n;
    inputArr(price, n);
    int ans = wineProblem(price, n);
    cout << ans;
}