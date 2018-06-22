// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

template <typename RandomAccessIterator>
RandomAccessIterator binarySearch(RandomAccessIterator begin, 
                                  RandomAccessIterator end, T elementToFound, 
                                  Criteria compare){
    RandomAccessIterator mid = (begin + end) / 2;
    while(begin <= end){
        if (compare(*mid, elementToFound)){
            // shall mid come before elementToFound in a sorted order
            
        }   
    }
}

int main(){
    
}