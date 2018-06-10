// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printHanoiSteps(int n, char src, char dest, char helper) {
    if (n == 0) return;

    printHanoiSteps(n - 1, src, helper, dest);
    cout << n << ": " << src << "-->" << dest << endl;
    printHanoiSteps(n - 1, helper, dest, src);
}

int main() {
    int n;
    cin >> n;
    printHanoiSteps(n, 'A', 'B' , 'C');
}