// 广度优先遍历 + new的使用
#include <unordered_map>
#include<vector>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;

        unordered_map<int, Node*> cloned;//这个相当于visited
        queue<Node*> my_que;

        my_que.push(node);
        cloned[node->val] = new Node(node->val);
        
        while(!my_que.empty()){
            Node* temp = my_que.front();
            my_que.pop();
            //cout<<temp->val;
            for(Node*i : temp->neighbors){
                if(!cloned[i->val]){
                    cloned[i->val] = new Node(i->val);
                    my_que.push(i);
                }
                cloned[temp->val]->neighbors.push_back(cloned[i->val]);//把第41行new的节点放到neighbor里面
            }
        }
        return cloned[node->val];
    }
};
