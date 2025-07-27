class MinStack {
private:
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {
        // Constructor
    }
    
    void push(int val) {
        s.push(val);
        // Push the minimum value so far
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
