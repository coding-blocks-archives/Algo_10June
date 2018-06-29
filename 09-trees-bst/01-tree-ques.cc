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

void levelPrint(TreeNode* root) {
    if (root == NULL) return;
    TreeNode* const MARKER = NULL;

    queue<TreeNode*> q;
    q.push(root);
    q.push(MARKER);

    while (q.empty() == false) {
        TreeNode* cur = q.front(); q.pop();
        if (cur == MARKER) {
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

TreeNode* getSuccessor(TreeNode* root, TreeNode* &successorParent) {
    if (root == NULL) return root;
    successorParent = root;
    TreeNode* successor = root->right ? root->right : NULL;
    while (successor && successor->left) {
        successorParent = successor;
        successor = successor->left;
    }
    return successor;
}

TreeNode* deleteFromBst(TreeNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteFromBst(root->left, key);
        return root;
    }

    if (key > root->data) {
        root->right = deleteFromBst(root->right, key);
        return root;
    }

    if (key == root->data) {
        // root has to be deleted
        // if root has only left child
        if (root->left == NULL) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }

        if (root->right == NULL) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }

        // root has 2 children
        TreeNode* successorParent = NULL;
        TreeNode* successor = getSuccessor(root, successorParent);
        if (successorParent == root) {
            successor->left = root->left;
            delete root;
            return successor;
        }
        else {
            successorParent->left = successor->right;
            successor->left = root->left;
            successor->right = root->right;
            delete root;
            return successor;
        }
    }
}


TreeNode* lca = NULL;
bool aPresent, bPresent;
// USE PASS BY REFERENCE INSTEAD OF GLOBAL VARIABLES
void findLcaBT(TreeNode* root, int a, int b) {
    if (root == NULL) return;

    findLcaBT(root->left, a, b);
    if (aPresent && bPresent) return;   // lca was there in left subtree

    if (root->data == a) aPresent = true;
    if (root->data == b) bPresent = true;

    bool maybe = false;
    if (aPresent or bPresent) {
        maybe = true;
    }
    
    findLcaBT(root->right, a, b);

    if (maybe && aPresent && bPresent) {lca = root; return;}
}

int main() {
    // TreeNode* root = createTree();  // its a bst
    // levelPrint(root);
    // cout << "\n==============\n";
    // int key; cin >> key;
    // root = deleteFromBst(root, key);
    // levelPrint(root);


    TreeNode* root = createTree();
    int a, b; cin >> a >> b;
    findLcaBT(root, a, b);
    cout << lca << " " << (lca ? lca->data : -1);
}