#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// clang-format off
struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x), left(left), right(right) {
    }
};
// clang-format off

// 前序遍历
void preorder(TreeNode* node, vector<int>& ans) {
    if (!node) return;  // 空树直接返回
    stack<TreeNode*> a_stack;  // 存储指针
    a_stack.push(node);
    while (!a_stack.empty()) {
        TreeNode* temp = a_stack.top();
        a_stack.pop();  // 访问过了就没有利用价值了，扔掉
        ans.push_back(temp->val);
        if (temp->right) a_stack.push(temp->right);
        if (temp->left) a_stack.push(temp->left);   //左子后入栈 先访问
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

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
    TreeNode*   root = buildTree();
    vector<int> pre = preorderTraversal(root);
    cout << "Preorder: ";
    for (int val : pre)
        cout << val << " ";
    cout << endl;
    return 0;
}

