// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;
void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

int histogramArea(int arr[], int n){
    typedef pair<int, int> ii;
    stack<pair<int, int> > s;
    int best = 0;

    for(int i = 0; i <= n; ++i){
        int y = i;
        int x = i;
        int cur = i == n ? -1 : arr[i];
        while(s.empty() == false && s.top().first >= cur){
            ii previous = s.top(); s.pop();
            int height = previous.first;
            x = previous.second;
            int curArea = height * (y - x);
            best = max(best, curArea);
        } 
        s.push(make_pair(cur, x));  
    }
    return best;
}


int main(){
    int arr[100]; int n;
    cin >> n;
    inputArr(arr, n);
    int ans = histogramArea(arr, n);
    cout << ans;    
}