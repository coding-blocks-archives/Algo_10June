// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputMat(char mat[][100], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cin >> mat[r][c];
        }
    }
}
void outputMat(char mat[][100], int m, int n){
    cout << "\n-----MAT Begins----\n";
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

void dfs(char board[][100], int m, int n, bool visited[][100], int srcRow, int srcCol){
    visited[srcRow][srcCol] = true;
    int rdir[] = {0, 1, 0, -1};
    int cdir[] = {1, 0, -1, 0};
    
    for(int i = 0;  i < 4; ++i){
        int nextRow = srcRow + rdir[i];
        int nextCol = srcCol + cdir[i];
        if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && 
            visited[nextRow][nextCol] == false &&
            board[nextRow][nextCol] == 'X'){
            dfs(board, m, n, visited, nextRow, nextCol);
        }
    }
}

int connectedComponenets(char board[][100], int m, int n){
    bool visited[100][100] = {};
    int numOfCC = 0;    // CC = connectedComponenets

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if (visited[i][j] == false and board[i][j] == 'X'){
                ++numOfCC;
                dfs(board, m, n, visited, i, j);
            }
        }
    }
    return numOfCC;
}

int main(){
    char board[100][100];
    int m, n;
    cin >> m >> n;
    inputMat(board, m, n);
    outputMat(board, m, n);
    int ans = connectedComponenets(board, m, n);
    cout << ans;   
}