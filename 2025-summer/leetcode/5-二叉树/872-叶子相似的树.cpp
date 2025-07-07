#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution_stack {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1,t2;
        t1 = return_leaf_value_sequence(root1);
        t2 = return_leaf_value_sequence(root2);
        return t1 == t2;
    }
    vector<int> return_leaf_value_sequence(TreeNode *root){
        vector<int> output;
        stack<TreeNode*> my_stack;
        my_stack.push(root);
        while(!my_stack.empty()){
            TreeNode *temp = my_stack.top();
            my_stack.pop();
            if(temp->right)my_stack.push(temp->right);
            if(temp->left) my_stack.push(temp->left);
            if((!temp->left)&&(!temp->right))output.push_back(temp->val);
        }
        return output;
    }
};
class Solution_recursion {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1,t2;
        dfs(root1,t1);
        dfs(root2,t2);
        return t1 == t2;
    }
    void dfs(TreeNode *root,vector<int> &output){
        if((!root->left)&&(!root->right))output.push_back(root->val);
        if(root->right)dfs(root->right,output);
        if(root->left) dfs(root->left,output);
    }
};