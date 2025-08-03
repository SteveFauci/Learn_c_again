#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorderT(root,ans);
        vector<int> temp = ans;
        sort(temp.begin(),temp.end());
        return temp == ans;
    }
    void inorderT(TreeNode* root,vector<int>&ans){
        if(!root)return;
        if(root->left)inorderT(root->left, ans);
        ans.push_back(root->val);
        if(root->right)inorderT(root->right, ans);
    }
};

    // vector<int> preTraverse(TreeNode *root){
    //     vector<int> ans;
    //     stack<TreeNode*> my_stack;
    //     if(!root)return {};
    //     my_stack.push(root);
    //     while(!my_stack.empty()){
    //         TreeNode* temp = my_stack.top();
    //         ans.push_back(temp->val);
    //         my_stack.pop();
    //         if(temp->right)my_stack.push(temp->right);
    //         if(temp->left)my_stack.push(temp->left);
    //     }
    //     return ans;
    // }