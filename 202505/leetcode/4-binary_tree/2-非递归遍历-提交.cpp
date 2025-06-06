#include<vector>
#include<stack>
using namespace std;
// clang-format off
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// clang-format on
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return vector<int>();
        stack<TreeNode*> my_stack;
        vector<int> ans;
        my_stack.push(root);
        while(!my_stack.empty()){
            TreeNode*temp = my_stack.top();
            my_stack.pop();
            ans.push_back(temp->val);
            if(temp->right)my_stack.push(temp->right);
            if(temp->left)my_stack.push(temp->left);
        }
        return ans;
    }
};