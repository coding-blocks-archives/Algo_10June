// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

int knightMinMoves(int board[][100], int dim, int xSrc, int ySrc, int xDest, int yDest) {
    queue<int> xCord;
    queue<int> yCord;
    bool visited[100][100] = {};
    int dist[100][100] = {};

    xCord.push(xSrc);
    yCord.push(ySrc);
    dist[xSrc][ySrc] = 0;

    int xDir[] = { +1, +2, +2, +1, -1, -2, -2, -1};
    int yDir[] = { +2, +1, -1, -2, -2, -1, +1, +2};

    while (xCord.empty() == false) {
        int x = xCord.front(); xCord.pop();
        int y = yCord.front(); yCord.pop();
        int distFrmSrc = dist[x][y];

        if (x == xDest and y == yDest) return distFrmSrc;

        for (int i = 0; i < 8; ++i) {
            int nextRow = x + xDir[i];
            int nextCol = y + yDir[i];
            if (nextRow >= 0 && nextRow < dim &&
                    nextCol >= 0 && nextCol < dim &&
                    visited[nextRow][nextCol] == false) {
                visited[nextRow][nextCol] = true;
                dist[nextRow][nextCol] = 1 + distFrmSrc;    // distFrmSrc is of parent
                xCord.push(nextRow);
                yCord.push(nextCol);
            }
        }
    }
    return -1;
}

int main() {
    int board[100][100];
    int dim, xSrc, ySrc, xDest, yDest;
    cin >> dim >> xSrc >> ySrc >> xDest >> yDest;
    int ans = knightMinMoves(board, dim, xSrc, ySrc, xDest, yDest);
    cout << ans;
}