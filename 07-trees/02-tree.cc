// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        data = d;
    }
};

TreeNode* createTree(){
    int x; cin >> x;
    if (x == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    root->left = createTree();
    root->right = createTree();
    return root;
}


int main(){
    TreeNode* root = createTree();
    printTree(root);    
}