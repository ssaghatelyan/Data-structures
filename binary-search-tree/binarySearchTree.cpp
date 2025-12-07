#include <iostream>
#include <limits>
#include <vector>

template <typename T>
class BinarySearchTree {
private:
    struct TreeNode {
        T data;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        explicit TreeNode(T val) : data(val) {}
    };

    TreeNode* root = nullptr;

    void printInorder(TreeNode* node) {
        if (!node) return;
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

    bool search(TreeNode* node, const T& val) {
        if (!node) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    bool isValidBST(TreeNode* node, T minVal, T maxVal) {
        if (!node) return true;
        if (node->data <= minVal || node->data >= maxVal) return false;
        return isValidBST(node->left, minVal, node->data) &&
               isValidBST(node->right, node->data, maxVal);
    }

    int height(TreeNode* node) {
        if (!node) return 0;
        return std::max(height(node->left), height(node->right)) + 1;
    }

    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return countNodes(node->left) + countNodes(node->right) + 1;
    }

    TreeNode* deleteNode(TreeNode* node, const T& val) {
        if (!node) return nullptr;
        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            if (!node->left) {
                TreeNode* tmp = node->right;
                delete node;
                return tmp;
            }
            if (!node->right) {
                TreeNode* tmp = node->left;
                delete node;
                return tmp;
            }
            TreeNode* succ = node->right;
            while (succ->left) succ = succ->left;
            node->data = succ->data;
            node->right = deleteNode(node->right, succ->data);
        }
        return node;
    }

public:
    void insert(const T& val) {
        if (!root) {
            root = new TreeNode(val);
            return;
        }
        TreeNode* cur = root;
        while (true) {
            if (val < cur->data) {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    return;
                }
                cur = cur->left;
            } else if (val > cur->data) {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    return;
                }
                cur = cur->right;
            } else return;
        }
    }

    void printInorder() {
        printInorder(root);
        std::cout << "\n";
    }

    bool search(const T& val) {
        return search(root, val);
    }

    T findMinBST() {
        if (!root) throw std::runtime_error("Empty tree");
        TreeNode* cur = root;
        while (cur->left) cur = cur->left;
        return cur->data;
    }

    T findMaxBST() {
        if (!root) throw std::runtime_error("Empty tree");
        TreeNode* cur = root;
        while (cur->right) cur = cur->right;
        return cur->data;
    }

    bool isValidBST() {
        return isValidBST(root,
            std::numeric_limits<T>::lowest(),
            std::numeric_limits<T>::max()
        );
    }

    int height() {
        return height(root);
    }

    int countNodes() {
        return countNodes(root);
    }

    void deleteValue(const T& val) {
        root = deleteNode(root, val);
    }
};

int main() {
    std::vector<int> nums = {1, 2, 4, 66, 788, 9, 123, 0, 54642, -567576, -548, 755};

    BinarySearchTree<int> t;
    for (int i : nums) t.insert(i);

    t.printInorder();
    std::cout << t.search(3) << "\n";
    std::cout << "Min: " << t.findMinBST() << "\n";
    std::cout << "Max: " << t.findMaxBST() << "\n";
    std::cout << t.isValidBST() << "\n";
    std::cout << t.height() << "\n";
    std::cout << t.countNodes() << "\n";

    t.deleteValue(66);
    t.printInorder();
}