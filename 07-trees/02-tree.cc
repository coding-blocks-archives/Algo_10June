// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
    TreeNode(int d){
        data = d;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

TreeNode* createTree(){
    int x; cin >> x;
    if (x == -1){
        return NULL;
    }

    TreeNode* root = new TreeNode(x);
    // cout << "Enter left child of " << x << " ";
    root->left = createTree();
    // cout << "Enter right child of " << x << " ";
    root->right = createTree();
    return root;
}

void inorder(const TreeNode* root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int height(const TreeNode* root){
    if (root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
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

        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int diameter1(TreeNode* root){
    if (root == NULL) return 0;

    int leftDia = diameter1(root->left);
    int rightDia = diameter1(root->right);
    int curDia = height(root->left) + height(root->right) + 1;
    return max(max(leftDia, rightDia), curDia);
}

class Pair{
public:
    int diameter;
    int height;
    Pair(int d, int h){ diameter = d; height = h;}
};

Pair diameter2(TreeNode* root){
    if (root == NULL){
        return Pair(0, 0);
    }

    Pair lt = diameter2(root->left);
    Pair rt = diameter2(root->right);
    int curHt = max(lt.height, rt.height) + 1;
    int curDia = leftHt + rightHt + 1;
    return Pair(curDia, curHt);
}

int heightWithDiameter(TreeNode* root, int& diameterComputedSoFar){
    if (root == NULL){
        return 0;
    }

    int lt = heightWithDiameter(root->left, diameterComputedSoFar);
    int rt = heightWithDiameter(root->right, diameterComputedSoFar);
    int curDia = lt + rt + 1;
    diameterComputedSoFar = max(diameterComputedSoFar, curDia);
    return max(lt, rt) + 1;
}

void connectLevels(TreeNode* root){
    
}


int main(){
    // TreeNode* root = createTree();
    // inorder(root);   
    // cout << "\n===========\n";
    // int ans = height(root);
    // cout << ans; 

    TreeNode* root = createTree();
    levelPrint(root);
}