#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int value): val(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* l, TreeNode* r): val(value), left(l), right(r) {}
};

void bfs(TreeNode* root) {
    // BFS functions
    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty()){
        TreeNode* neg = q.front();
        cout<<neg->val<<" ";
        q.pop();
        if(neg->left != NULL){
            q.push(neg->left);
        }
        if(neg->right != NULL){
            q.push(neg->right);
        }
    }
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
