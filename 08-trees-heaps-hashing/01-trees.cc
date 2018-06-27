// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

TreeNode* createTree() {
    int x; cin >> x;
    if (x == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree();
    // cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void inorder(const TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelPrint(TreeNode* root){
    if (root == NULL) return;
    TreeNode* const MARKER = NULL;

    queue<TreeNode*> q;
    q.push(root);
    q.push(MARKER);

    while(q.empty() == false){
        TreeNode* cur = q.front(); q.pop();
        if (cur == MARKER){
            // cur level is processed....all children of this level are processed
            // this signfies next level has ended
            cout << endl;
            if (q.empty() == false) q.push(MARKER);
            continue;
        }

        cout << cur->data << "(" << (cur->next ? cur->next->data : 0) << ") ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

void connectLevels(TreeNode* root){
    TreeNode* leftMostNode = NULL;
    TreeNode* child = NULL;
    TreeNode* cur = root;

    while(cur){
        leftMostNode = NULL;    // assumption
        child = NULL;
        while(cur){
            if (cur->left){
                if (leftMostNode == NULL) leftMostNode = cur->left;
                if (child == NULL){
                    child = cur->left;
                }
                else {
                    child ->next = cur->left;
                    child = child->next;
                } 
            }

            if (cur->right){
                if (leftMostNode ==  NULL) leftMostNode = cur->right;
                if (child == NULL){
                    child = cur->right;
                }
                else {
                    child->next = cur->right;
                    child = child->next;
                }
            }
            cur = cur->next;
        }
        cur = leftMostNode;
    }
}

int main() {
    TreeNode* root = createTree();
    connectLevels(root);
    levelPrint(root);


}