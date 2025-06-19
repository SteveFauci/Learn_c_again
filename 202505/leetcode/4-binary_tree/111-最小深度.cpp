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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> my_que;
        if(!root)return 0;
        my_que.push(root);
        int cnt = 1;
        while(!my_que.empty()){
            int sz = my_que.size();
            while(sz--){
                TreeNode* temp = my_que.front();
                if(!temp->left&&!temp->right)return cnt;
                if(temp->left)my_que.push(temp->left);
                if(temp->right)my_que.push(temp->right);
                my_que.pop();
            }
            cnt++;
        }
        return -1;
    }
};