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
    int llen = 0 , rlen = 0;
    void dfs(TreeNode* root){
        if(root->left){
            llen++;
            dfs(root->left);
        }
        if(root->right){
            rlen++;
            dfs(root->right);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return llen + rlen;
    }
};