#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if(!root) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return std::max(root->data, std::max(leftMax, rightMax));
}

int findMin(TreeNode* root) {
    if(!root) return INT_MAX;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return std::min(root->data, std::min(leftMin, rightMin));
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    
    int maxVal = findMax(root);  // maxVal = 8
    int minVal = findMin(root);  // minVal = 1
    
    std::cout << "Max value: " << maxVal << "\n";
    std::cout << "Min value: " << minVal << "\n";
}