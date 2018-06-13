// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void clearBoard(char board[][100], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            board[r][c] = 'X';
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

bool canPlace(char board[][100], int N, int r, int c){
    for(int x = 0; x < N; ++x){
        if (board[x][c] == 'Q') return false;
    }

    int rowDir[] = {-1, -1};
    int colDir[] = {-1, +1};
    for(int dir = 0; dir < 2; ++dir){
        for(int dist = 1; dist < N; ++dist){
            int nextRow = r + dist * rowDir[dir];
            int nextCol = c + dist * colDir[dir];
            if ((nextRow < 0 or nextRow >= N) or (nextCol < 0 or nextCol >= N)){
                break;
            }
            // now i can check safely, huhhh!
            if (board[nextRow][nextCol] == 'Q') return false;
        }
    }
    return true;
}

bool solveNQueen(char board[][100], int N, int r){
    if (r == N){
        return true;
    }
    // lets try to place a queen in row r
    for(int c = 0; c < N; ++c){
        bool check = canPlace(board, N, r, c);
        if (check == true){
            board[r][c] = 'Q';  // place the queen
            bool status = solveNQueen(board, N, r + 1);
            if (status == true){
                return true;
            }
            else {
                board[r][c] = 'X';  // reset the cell
            }
        }
    }
    return false;
}

int main(){
    char board[100][100];
    int N; cin >> N;
    clearBoard(board, N, N);

    bool success = solveNQueen(board, N, 0);
    if (success){
        outputMat(board, N, N);
    }   
    else {
        cout << "Sorry Man! Your castle is too small to handle queens.." 
             << endl;
    }
}