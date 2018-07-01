// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool regexMatch(char str[], char pattern[]) {
    if (*str == '\0' && *pattern == '\0') {return true;}

    if (*pattern == '\0') { return false; }

    if (*str == '\0'){
        if (*pattern == '*') return regexMatch(str, pattern + 1);
        return false;
    }

    // NOW i have atleast one one char in both string and pattern
    if (*pattern == '?' or *pattern == *str){
        return regexMatch(str + 1, pattern + 1);
    }

    if (*pattern == '*'){
        return 
            /* '*' matches zero char in the string*/
            regexMatch(str, pattern + 1) or
            /* '*'' matches AT LEAST ONE char in the string */
            regexMatch(str + 1, pattern);
    }

    // the current char in string can NOT be matched with any of the char
    return false;
}


int main() {
    char pattern[100], str[100];
    cin >> str >> pattern;
    bool ans = regexMatch(str, pattern);
    cout << ans;
}