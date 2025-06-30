// clang-format off
#include<queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return nullptr;
        queue<Node*>my_que;
        my_que.push(root);
        while (!my_que.empty()) {
            int   sz = my_que.size();
            // if(sz == 1)temp->next = nullptr;
            // clang-format on
            for (int i = 0; i < sz; i++) {
                Node* temp = my_que.front();
                if (temp->left) my_que.push(temp->left);
                if (temp->right) my_que.push(temp->right);
                my_que.pop();
                if (i + 1 == sz) temp->next = nullptr;
                else {
                    Node* temp2 = my_que.front();
                    temp->next = temp2;
                }
            }
        }
        return root;
    }
};