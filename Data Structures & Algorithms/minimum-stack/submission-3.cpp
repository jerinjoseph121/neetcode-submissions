class MinStack {
public:
    stack<pair<int, int>> st;
    
    MinStack() {
    }
    
    void push(int val) {
        int minVal;

        if (st.empty()) {
            minVal = INT_MAX;
        } else {
            minVal = st.top().second;
        }
        
        minVal = min(minVal, val);

        st.push({val, minVal});

        return;
    }
    
    void pop() {
        st.pop();

        return;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
