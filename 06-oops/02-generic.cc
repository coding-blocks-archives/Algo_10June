// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;
template<typename T, typename V>
void print(T arr[], int n, V printElement) {
    for (int i = 0; i < n; ++i) {
        printElement(arr[i]);
        cout << endl;
    }
}

void printInt(int x){
    cout << x;
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

void printElephant(Elephant E){
    cout << E.name << " " << E.wt;
}

int main() {
    int arr[] = {1, 2, 3};
    print(arr, 3, printInt);
    char arr2[] = "Abc";
    // print(arr2, 3);

    Elephant E[] = {
        {"Raju", 300},
        {"Hachi", 1000},
        {"Jumbo", 1200}
    };
    print(E, 3, printElephant);
}