#include<stack>
#include<algorithm>
using namespace std;
class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        my_stack.push(val);
        if(minstack.empty())minstack.push(val);
        else minstack.push(min(val,minstack.top()));
    }
    
    void pop() {
        my_stack.pop();
        minstack.pop();
    }
    
    int top() {
        return my_stack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
private:
    stack<int> my_stack;
    stack<int> minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */