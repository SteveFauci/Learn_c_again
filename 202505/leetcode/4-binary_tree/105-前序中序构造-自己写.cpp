#include <unordered_map>
#include <vector>
// clang-format off
using namespace std;
struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};
class Solution {
private:
    unordered_map<int, int> my_map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sz = preorder.size();
        for(int i = 0; i < sz; i++){
            my_map[inorder[i]] = i;
        }
        return myfunc(preorder,inorder,0,sz-1,0,sz-1);
    }
    TreeNode* myfunc(vector<int>&p,vector<int>&i,int pl,int pr,int il,int ir){
        if(pl>pr)return nullptr;
        TreeNode* root = new TreeNode(p[pl]);
        int pi = my_map[p[pl]];
        int l_sz = pi - il;
        root->left = myfunc(p,i,pl+1,pl+l_sz,il,pi-1);
        root->right = myfunc(p,i,pl+l_sz+1,pr,pi+1,ir);
        return root;
    }
};
