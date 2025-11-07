#include <iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
    if(!root) return;
    std::swap(root->left, root->right);
    
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    std::cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    printInOrder(root);
    std::cout << "\n";
    mirrorTree(root);
    // Теперь: root->right = 2, root->left = 3, root->right->right = 4
    printInOrder(root);
}