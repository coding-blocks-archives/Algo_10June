// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

bool regexMatch(char str[], char pattern[]) {
    if (*str == '\0' && *pattern == '\0') {return true;}

    if (*pattern == '\0') { return false; }

    if (*str == '\0') {
        if (*pattern == '*') return regexMatch(str, pattern + 1);
        return false;
    }

    // NOW i have atleast one one char in both string and pattern
    if (*pattern == '?' or * pattern == *str) {
        return regexMatch(str + 1, pattern + 1);
    }

    if (*pattern == '*') {
        return
            /* '*' matches zero char in the string*/
            regexMatch(str, pattern + 1) or
            /* '*'' matches AT LEAST ONE char in the string */
            regexMatch(str + 1, pattern);
    }

    // the current char in string can NOT be matched with any of the char
    return false;
}

bool regexMatchDP(char* str, char* pattern) {
    int lenStr = strlen(str);
    int lenPattern = strlen(pattern);
    bool dp[100][100];

    for (int i = 0; i <= lenPattern; ++i) {
        for (int j = 0; j <= lenStr; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = true;
            }
            else if (i == 0) {
                dp[i][j] = false;
            }
            else if (j == 0) {
                char curCharInPattern = pattern[i - 1];
                dp[i][j] = dp[i - 1][j] && curCharInPattern == '*';
            }
            else {
                char curCharInPattern = pattern[i - 1];
                char curCharInStr = str[j - 1];
                if (curCharInPattern == '?' or curCharInPattern == curCharInStr) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (curCharInPattern == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[lenPattern][lenStr];
}


int main() {
    char pattern[100], str[100];
    // cin >> str >> pattern;
    cin.getline(str, 90);
    cin.getline(pattern, 90);
    bool ans = regexMatch(str, pattern);
    cout << ans;
}