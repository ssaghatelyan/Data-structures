#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrder(TreeNode* root) {
    if(!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        std::cout << curr->data << " ";
        
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    levelOrder(root);
    // Вывод: 1 2 3 4 5
}