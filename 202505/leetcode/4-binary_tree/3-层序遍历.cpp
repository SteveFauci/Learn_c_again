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
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()){
            auto a = my_queue.size();
            vector<int> layer; //每次都重新声明，循环过后不必clear
            while(a--){
                TreeNode*temp = my_queue.front();
                if(temp->left)my_queue.push(temp->left);
                if(temp->right)my_queue.push(temp->right);
                layer.push_back(temp->val);
                my_queue.pop();
            }
            //my_queue.clear();
            ans.push_back(layer);
        }
        return ans;
    }
};