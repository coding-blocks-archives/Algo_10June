// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;
template <class T>
void outputArr(T arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

template <typename T, typename Criteria>
void bubbleSort(T arr[], int n, Criteria compare) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (compare(arr[j], arr[j + 1])) {
                // if arr[j] > arr[j + 1] : true
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


bool foo(int x, int y){
    return x > y;
}

class Elephant{
public:
    char name[20];
    int wt;
    Elephant(const char* n, int w){
        strcpy(name, n);
        wt = w;
    }
};

bool compareElephant(const Elephant& A, const Elephant& B){
    return A.wt > B.wt;
}


int main() {
    int arr[] = {5, 4, 3, 2, 1};
    char arr2[] = "deav";
    Elephant E[] = {
        {"Raju", 1300},
        {"Hachi", 1200},
        {"Jumbo", 1100}
    };
    bubbleSort(E, 3, compareElephant);
    cout << E[0].wt << " " << E[1].wt << " " << E[2].wt << endl;
}