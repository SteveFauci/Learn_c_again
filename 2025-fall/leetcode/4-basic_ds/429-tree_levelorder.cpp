#include<vector>
#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*> my_que;
        vector<vector<int>> ans;
        my_que.push(root);
        while(!my_que.empty()){
            vector<int> cur_lyr;
            int size = my_que.size();
            for(int j = 0; j < size; j++){
                Node* temp = my_que.front();
                my_que.pop();
                for(int i = 0; temp && i < temp->children.size(); i++){
                    my_que.push(temp->children[i]);
                }
                cur_lyr.push_back(temp->val);
            }
            ans.push_back(cur_lyr);
        }
        return ans;
    }
};