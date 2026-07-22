class MinStack {
public:
    stack<int> st;
    int minVal;
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int val) {
        minVal = min(minVal, val);
        st.push(val);

        return;
    }
    
    void pop() {
        int topVal = st.top();

        if (topVal > minVal) {
            st.pop();
            return;
        }

        st.pop();

        minVal = INT_MAX;

        stack<int> temp;

        while (!st.empty()) {
            topVal = st.top();
            st.pop();

            minVal = min(minVal, topVal);

            temp.push(topVal);
        }

        while (!temp.empty()) {
            topVal = temp.top();
            temp.pop();

            st.push(topVal);
        }

        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};
