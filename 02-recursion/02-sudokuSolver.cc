// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <math.h> // cmath
using namespace std;
void inputMat(int mat[][50], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cin >> mat[r][c];
        }
    }
}
void outputMat(int mat[][50], int m, int n){
    cout << "\n-----MAT Begins----\n";
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

bool canPlace(int board[][50], int N, int r, int c, int num){
    for(int x = 0; x < N; ++x){
        if (board[r][x] == num or board[x][c] == num){
            return false;
        }
    }

    int rootN = sqrt(N);
    int subBoxStartRow = r - r % rootN;
    int subBoxStartCol = c - (c % rootN);
    for(int i = subBoxStartRow; i < subBoxStartRow + rootN; ++i){
        for(int c = subBoxStartCol; c < subBoxStartCol + rootN; ++c){
            if (board[i][c] == num){
                return false;
            }
        }
    }
    return true;
}


bool solveSudoku(int board[][50], int N, int r, int c){
    if (r == N){
        // no row to work 
        return true;
    }

    // ensure c is within the range
    if (c == N){
        return solveSudoku(board, N, r + 1, 0);
    }

    if (board[r][c] != 0){
        // it's a fixed cell
        return solveSudoku(board, N, r , c + 1);
    }

    // if the cell is not a fixed cell
    for(int num = 1; num <= N; ++num){
        bool check  = canPlace(board, N, r, c, num);
        if (check == true){
            board[r][c] = num;
            bool status = solveSudoku(board, N, r, c + 1);
            if (status == true){
                return true;
            }
            else {
                board[r][c] = 0;
            }
        }
    }
    return false;
}


int main(){
    int board[50][50];
    int N; cin >> N;
    inputMat(board, N, N);
    bool status = solveSudoku(board, N, 0, 0);
    if (status == true){
        outputMat(board, N, N);
    }
    else {
        cout << "Sorry. Can't solve sudoku. Neither you can ;)";
    }
}