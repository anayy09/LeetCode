#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> istack;
    stack<int> minStack;

public:
    MinStack() {
       
    }
    
    void push(int val) {
        istack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (istack.top() == minStack.top()) {
            minStack.pop();
        }
        istack.pop();
    }
    
    int top() {
        return istack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */