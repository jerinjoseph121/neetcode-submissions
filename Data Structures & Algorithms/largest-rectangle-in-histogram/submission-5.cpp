class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;

        int res = 0;

        int leftSide, rightSide;

        for (int i = 0; i < n; i++) {
            rightSide = i - 1;
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int currIdx = st.top();
                st.pop();

                while(!st.empty() && heights[st.top()] == heights[currIdx]) {
                    st.pop();
                }

                if (!st.empty()) {
                    leftSide = st.top() + 1;
                } else {
                    leftSide = 0;
                }

                res = max(res, heights[currIdx] * (rightSide - leftSide + 1));
            }

            st.push(i);
        }

        rightSide = n - 1; 

        while (!st.empty()) {
            int currIdx = st.top();
            st.pop();

            while(!st.empty() && heights[st.top()] == heights[currIdx]) {
                st.pop();
            }

            if (!st.empty()) {
                leftSide = st.top() + 1;
            } else {
                leftSide = 0;
            }

            res = max(res, heights[currIdx] * (rightSide - leftSide + 1));
        }

        return res;
    }
};
