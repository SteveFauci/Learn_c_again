#include<algorithm>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return (!root) ? 0 : (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }//递归。根节点最大深度 = 1 + max(左子树深,右子树深)
};
// BFS
class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int nums = 0;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()){
            auto a = my_queue.size();
            while(a--){
                TreeNode* temp = my_queue.front();
                if(temp->left)my_queue.push(temp->left);
                if(temp->right)my_queue.push(temp->right);
                my_queue.pop();
            }
            nums++;
        }
        return nums;
    }
};
//dfs好像要两个栈，还不会写。
//#include<stack>