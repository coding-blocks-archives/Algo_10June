// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
#include <iomanip>
#include <cctype>
using namespace std;
const int CHAR_SET_SZE = 5;

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
public:
    Trie() {
        root = new TrieNode();
        numberOfWords = 0;
    }

    void insert(const string& word) {
        TrieNode* curNode = root;

        for (int i = 0; i < word.size(); ++i) {
            char curChar = word[i] - (isalpha(word[i]) ? 'a' : '0');
            TrieNode* &nextNode = curNode->children[curChar];
            if (nextNode == NULL) {
                nextNode = new TrieNode();
            }
            curNode = nextNode;
        }
        curNode->isTerminal = true;
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
};

int main() {
    Trie t;
    // t.printTrie();
    t.insert("ab");
    t.insert("bd");
    t.insert("bc");
    t.printTrie();
    // t.insert("be");

}