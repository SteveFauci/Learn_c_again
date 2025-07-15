#include<unordered_map>
#include<vector>
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
// 递归法
class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& p, const vector<int>& i, int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        // 在中序遍历中定位根节点
        int pi = index[p[pl]];
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(p[pl]);
        // 得到左子树中的节点数目
        int l_sz = pi - il;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(p, i, pl + 1, pl + l_sz, il, pi - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(p, i, pl + l_sz + 1, pr, pi + 1, ir);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
