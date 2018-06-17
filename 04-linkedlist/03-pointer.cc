// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x) cout << (#x) << "\t:" << x << endl




int main() {
    // int arr[4] = {1,2,3};
    // print(arr[0]);
    // print(arr[3]);

    // int* p;
    // cout << *p;

    // int x = 0;
    // int* p ; // undefined
    // int* p = NULL;

    // int* q, r;      // q is ptr and r is int
    // print(p);
    // print(*p);

    // int* ptr_i;
    // double* ptr_d;

    // int arr[3] = {1, 2, 3};
    // int* ptr1 = arr;
    // int* ptr2 = &arr[0];
    // print(ptr1);
    // print(ptr2);

    // int arr[3] = {1, 2, 3};
    // int* ptr1 = arr;
    // char str[] = {'H', 'e'};

    // char* ptr2 = &str[0];
    // cout << ptr1 << endl;  // prints address
    // cout << ptr2 << endl;  // prints value...by design of cout
    // cout << (int*)ptr2 << endl;

    // int arr[] = {1, 2, 3, 4};
    // cout << &arr[2] - (char*)&arr[0];
    // int arr[] = {1, 2, 3, 4};
    // print(arr);
    // print(&arr[0]);
    // print(&arr);

    // print((arr + 1) - arr);
    // print(&arr[0] + 1);
    // print(&arr + 1);
    // print((&arr + 1)-(&arr));

    // int *p1 = arr;
    // int (*p2)[4] = &arr;

    // int*p2[4];
    // int(*p2)[4];

    void f1(int arr[], int n);
    void f2(int mat[][4]);

    int arr[10];        // ptr to an int
    int mat[2][4];      // ptr to a row --> ptr to an array

    // sizeof (arr) / sizeof (arr[0]);

    f1(arr, 4);
    f2(mat);
}

void f1(int arr[], int n){} // int* arr
void f2(int mat[][4]){}     // int (*mat)[4]