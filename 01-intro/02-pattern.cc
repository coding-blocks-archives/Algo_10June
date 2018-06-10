// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int nLines;
    cin >> nLines;

    int incLines = nLines / 2 + 1;
    int decLines = nLines - incLines;

    void printSpace(int);   // declarations
    void printStar(int x);

    for(int curRow = 1; curRow <= incLines; ++curRow){
        printSpace(incLines - curRow);
        printStar(2*curRow - 1);
        cout << endl;
    }    
    // print dec pattern
    int nspace = 1;
    for(int curRow = decLines; curRow >= 1; --curRow){
        printSpace(nspace); ++nspace;
        printStar(2 * curRow - 1);
        cout << endl;
    }
}

void printSpace(int n){
    for(int i = 0; i < n; ++i){
        cout << " ";
    }
}

void printStar(int n){
    for(int i = 0; i < n; ++i){
        cout << "*";
    }
}