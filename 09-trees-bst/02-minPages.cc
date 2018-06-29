// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <numeric>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

enum state {FAILURE = 0, SUCCESS = 1};
state allocate(int arr[], int nbooks, int nstud, int guess) {
    int curStudent = 1;
    int numPagesAllocatedSoFar = 0;

    for (int i = 0; i < nbooks; ++i) {
        int curPages = arr[i];
        if (numPagesAllocatedSoFar + curPages <= guess) {
            // we can allocate cur book to the student
            numPagesAllocatedSoFar += curPages;
        }
        else if (curPages <= guess) {
            // allocate this book to the next student
            ++curStudent;
            numPagesAllocatedSoFar = curPages;
            if (curStudent > nstud) return FAILURE;
        }
        else {
            // signifies that curPages is greater than guess. This book can't be allocated
            // to any student 
            return FAILURE;
        }
    }
    return SUCCESS;
}


int minPages(int arr[], int nbooks, int nstud) {
    int be = 0;
    int en = accumulate(arr, arr + nbooks, 0);
    int ans = en;

    // while range is valid
    while (be <= en) {
        int mid = (be + en) / 2;
        state check = allocate(arr, nbooks, nstud, mid);
        if (check == SUCCESS) {
            // my mid was right
            ans = mid;
            en = mid - 1;
        }
        else {
            // mid was too small....can't allocate
            be = mid + 1;
        }
    }
    return ans;
}


int main() {
    int arr[100];
    int nbooks; cin >> nbooks;
    int nstud;  cin >> nstud;
    inputArr(arr, nbooks);
    int ans = minPages(arr, nbooks, nstud);
    cout << ans;
}