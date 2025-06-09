#include <stack>
// clang-format off
using namespace std;
struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
// 递归法：到叶子节点时，判断是否为目标
// 否则减去当前节点的值，继续往下一层搜索。
class Solution0 {
  public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

// 非递归：
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> my_stack;
        if(!root)return false;
        my_stack.push(root);
        while(!my_stack.empty()){
            TreeNode* temp = my_stack.top();
            my_stack.pop();
            if(!temp->right&&!temp->left&&temp->val == targetSum)return true;
            if(temp->right){temp->right->val+=temp->val;my_stack.push(temp->right);}
            if(temp->left){temp->left->val+=temp->val;my_stack.push(temp->left);}
        }
        return false;
    }
};