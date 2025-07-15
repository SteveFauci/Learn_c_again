struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_myself {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        my_merge(root1,root2);
        return root1;
    }
    void my_merge(TreeNode*root1,TreeNode* root2){
        // 只改root1
        if(root1 && root2)root1->val += root2->val;
        if(root1->right && root2->right)my_merge(root1->right, root2->right);
        if(root1->left && root2->left)my_merge(root1->left, root2->left);
        if(!root1->left && root2->left)root1->left = root2->left;
        if(!root1->right && root2->right)root1->right = root2->right;
    }
};
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1)return root2;
        if(!root2)return root1;
        return new TreeNode(root1->val+root2->val,
            mergeTrees(root1->left, root2->left),
            mergeTrees(root1->right, root2->right));
    }
};