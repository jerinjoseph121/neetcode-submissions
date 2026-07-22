class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);

        if (!minSt.empty()) {
            int minVal = minSt.top();
            if (val <= minVal) {
                minSt.push(val);
            }
        } else {
            minSt.push(val);
        }

        return;
    }
    
    void pop() {
        int topVal = st.top();
        st.pop();

        int minVal = minSt.top();

        if (topVal == minVal) {
            minSt.pop();
        }

        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
