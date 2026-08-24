class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        minElement = min(minElement, val);
        elementStack.push(val);
        minStack.push(minElement);
    }
    
    void pop() {
        elementStack.pop();
        minStack.pop();
        minElement = minStack.empty() 
            ? INT_MAX 
            : minStack.top();
    }
    
    int top() {
        return elementStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    stack<int> elementStack;
    stack<int> minStack;
    int minElement = INT_MAX;
};
