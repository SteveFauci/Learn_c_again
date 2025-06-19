#include<vector>
#include<queue>
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return {};
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()){
            vector<int> temp;
            int sz = my_queue.size();
            while(sz--){
                TreeNode* tmp =my_queue.front();
                if(tmp->left)my_queue.push(tmp->left);
                if(tmp->right)my_queue.push(tmp->right);
                temp.push_back(tmp->val);
                my_queue.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};