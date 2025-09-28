class MinStack {
private:
    stack<int> st;
    stack<int> mnSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mnSt.push(mnSt.empty() ? val : min(val, mnSt.top()));
    }
    
    void pop() {
        st.pop();
        mnSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnSt.top();
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