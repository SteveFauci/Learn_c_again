#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    stack<TreeNode*> my_stack;
    TreeNode*ptr = new TreeNode;
    BSTIterator(TreeNode* root) {
        ptr = root;
        my_stack.push(ptr);
    }
    int next() {
        while(ptr){
            my_stack.push(ptr);
            ptr = ptr->left;
        }
        ptr = my_stack.top();
        my_stack.pop();
        int ans = ptr->val;
        ptr=ptr->right;
        return ans;
    }
    
    bool hasNext() {
        return ptr||(!my_stack.empty());
    }
};
// 垃圾解法：不是迭代器，而是通过数组访问。。注意下构造函数的应用
class BSTIterator0 {
public:
    vector<int> my_vect;
    int ptr = -1;
    int sz;
    BSTIterator0(TreeNode* root) {
        inorderT(root);
        sz = my_vect.size();
    }
    void inorderT(TreeNode* root){
        if(!root)return;
        if(root->left)inorderT(root->left);
        my_vect.push_back(root->val);
        if(root->right)inorderT(root->right);
    }

    int next() {
        return my_vect[++ptr];
    }
    
    bool hasNext() {
        return ptr<sz-1;
    }
};
