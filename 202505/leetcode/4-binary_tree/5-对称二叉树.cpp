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
    bool isSymmetric(TreeNode* root) {
        if(!root)return false;
        else if(!root->left && !root->right) return true;
        else if(!root->left || !root->right) return false;
        else{
            return recursive(root->left,root->right);
        }
    }
    bool recursive(TreeNode*left,TreeNode*right){
        if(!left&&!right)return true;
        else if(!left||!right)return false;
        else if(left->val == right->val && left && right)return recursive(left->left, right->right)&&recursive(left->right, right->left);
        else return false;
    }
};