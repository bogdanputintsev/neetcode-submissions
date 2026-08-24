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

// C P-2 P0 P-3 M P T M P2 P-4 P3 M P M P T M P T M
//                             .
// { -2,  0,  2, -4,  3, }
// { -2, -2, -2, -4, -4,}
