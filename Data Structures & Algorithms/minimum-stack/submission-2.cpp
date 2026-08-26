class MinStack {
public:
    stack<int> curr_stack;
    stack<int> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        curr_stack.push(val);
        val = min(val, min_stack.empty() ? val : min_stack.top());
        min_stack.push(val);
    }
    
    void pop() {
        curr_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return curr_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
