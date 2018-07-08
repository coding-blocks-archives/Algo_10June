// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cctype>
#define print(x) cout << #x << ": " << x << endl;
using namespace std;
const int CHAR_SET_SZE = 36;

class TrieNode {
public:
    bool isTerminal;
    TrieNode* children[CHAR_SET_SZE];
    TrieNode() {
        isTerminal = false;
        fill(children, children + CHAR_SET_SZE, (TrieNode*)NULL);
    }

    void printTrieNode() {
        if (isTerminal == true) cout << "(" << isTerminal << ")";
        for (int i = 0; i < CHAR_SET_SZE; ++i) {
            cout << setw(9) << children[i];
        }
        cout << endl;
    }
};

class Trie {
    TrieNode* root;
    int numberOfWords;

    int charToIndex(char c) {
        if (isalpha(c)) {
            c -= 'a';
        }
        else {
            const int offset = 26;
            c = c - '0' + offset;
        }
    }

public:
    Trie() {
        root = new TrieNode();
        numberOfWords = 0;
    }

    void insert(const string& word) {
        TrieNode* curNode = root;

        for (int i = 0; i < word.size(); ++i) {
            int curChar = charToIndex(word[i]);
            TrieNode* &nextNode = curNode->children[curChar];
            if (nextNode == NULL) {
                nextNode = new TrieNode();
            }
            curNode = nextNode;
        }
        curNode->isTerminal = true;
        ++numberOfWords;
    }

    bool search(const string& word) {
        TrieNode* curNode = root;
        for (int i = 0; i < word.size() && curNode; ++i) {
            int curChar = charToIndex(word[i]);
            curNode = curNode->children[curChar];
        }
        return curNode ? curNode->isTerminal == true : false;
    }

    void printTrie() {
        queue<TrieNode*> q;
        q.push(root);
        while (q.empty() == false) {
            TrieNode* curNode = q.front(); q.pop();
            if (curNode) {
                curNode->printTrieNode();
                cout << "--------\n";
                for (int i = 0; i < CHAR_SET_SZE; ++i) {
                    if (curNode->children[i]) q.push(curNode->children[i]);
                }
            }
            else {
                cout << setw(8) << 0;
            }
        }
    }

    bool andFunction(bool x, TrieNode* y) {
        return x && y == NULL;
    }

    TrieNode* deleteTrieNode(TrieNode* root) {
        // bool isAllNull = accumulate(&root->children[0],
        //                             &root->children[0] + CHAR_SET_SZE,
        //                             true, andFunction);
        bool isAllNull = true;
        for(int i = 0; i < CHAR_SET_SZE; ++i){
            isAllNull = isAllNull && (root->children[i] == NULL);
        }
        if (isAllNull && root->isTerminal == false) {
            delete root;
            return NULL;
        }
        return root;
    }

    TrieNode* remove(const string& s, int beginIdx, TrieNode* root) {
        if (root == NULL) return NULL;

        if (beginIdx == s.size()) {
            // all char have been considered
            root->isTerminal = false;
            return deleteTrieNode(root);
        }

        int curChar = charToIndex(s[beginIdx]);
        TrieNode* remTrie = remove(s, beginIdx + 1, root->children[curChar]);
        root->children[curChar] = remTrie;
        if (remTrie) return root;
        return deleteTrieNode(root);
    }

    bool remove(const string& word){
        TrieNode* ans = remove(word, 0, root);
        return ans == NULL;
    }
};

int main() {
    Trie t;
    t.insert("bat");
    t.insert("batman");
    t.remove("batman");

    print(t.search("batman"));
    print(t.search("bat"));

    // t.printTrie();
    
    // print(t.search("batman"));

    // t.insert("bat");
    // t.insert("batman");
    // t.insert("bet");
    // print(t.search("bat"));
    // print(t.search("batman"));
    // print(t.search("catwoman"));
    // print(t.search("bet"));

}