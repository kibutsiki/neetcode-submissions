class MinStack {
public:
    stack<int> curr_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        curr_stack.push(val);
    }
    
    void pop() {
        curr_stack.pop();
    }
    
    int top() {
        return curr_stack.top();
    }
    
    int getMin() {
        int min_val = curr_stack.top();
        stack<int> temp_stack;
        while(curr_stack.size()){
            min_val = min(min_val, curr_stack.top());
            temp_stack.push(curr_stack.top());
            curr_stack.pop();
        }

        while(temp_stack.size()){
            curr_stack.push(temp_stack.top());
            temp_stack.pop();

        }
        return min_val;
    }
};
