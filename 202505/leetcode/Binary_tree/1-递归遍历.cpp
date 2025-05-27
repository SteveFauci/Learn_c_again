#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {
    }
};

// 前序遍历
void preorder(TreeNode* node, vector<int>& ans) {
    if (!node)
        return;
    ans.push_back(node->val);
    preorder(node->left, ans);
    preorder(node->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

// 中序遍历
void inorder(TreeNode* node, vector<int>& ans) {
    if (!node)
        return;
    inorder(node->left, ans);
    ans.push_back(node->val);
    inorder(node->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

// 后序遍历
void postorder(TreeNode* node, vector<int>& ans) {
    if (!node)
        return;
    postorder(node->left, ans);
    postorder(node->right, ans);
    ans.push_back(node->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

// 释放树（后序遍历删除）
void deleteTree(TreeNode* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 构建树
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    TreeNode* root = buildTree();

    vector<int> ino = inorderTraversal(root);
    vector<int> pre = preorderTraversal(root);
    vector<int> pos = postorderTraversal(root);

    cout << "Inorder: ";
    for (int val : ino)
        cout << val << " ";
    cout << endl;

    cout << "Preorder: ";
    for (int val : pre)
        cout << val << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int val : pos)
        cout << val << " ";
    cout << endl;

    deleteTree(root);
    return 0;
}