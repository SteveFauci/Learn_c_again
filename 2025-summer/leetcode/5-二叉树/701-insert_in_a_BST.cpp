
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        helper(root,val);
        return root;
    }

    TreeNode* helper(TreeNode* root, int val) {
        if (!root->left && val < root->val) {
            TreeNode* temp = new TreeNode(val);
            root->left = temp;
        }
        if(!root->right && val > root->val) {
            TreeNode* temp = new TreeNode(val);
            root->right = temp;
        }
        if(root->left && val < root->val)return helper(root->left,val);
        if(root->right && val < root->val)return helper(root->right,val);
        return {};
    }
};