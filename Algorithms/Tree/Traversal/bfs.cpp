#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value): val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* l, TreeNode* r){
        val = value, left = l, 
        right = r;
    }
        
};

void bfs(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return;
    }
    if (root->left == nullptr) {}
    bfs(root->left);
    bfs(root->right);
}

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "BFS Traversal: ";
    bfs(root);
    cout << endl;

    return 0;
}
