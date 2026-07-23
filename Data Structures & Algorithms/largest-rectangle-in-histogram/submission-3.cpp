class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> rightMaxIdx(n);
        vector<int> leftMaxIdx(n);

        stack<pair<int, int>> st;

        int currLeftMaxIdx;

        for (int i = 0; i < n; i++) {            
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                currLeftMaxIdx = st.top().second + 1;
            } else {
                currLeftMaxIdx = 0;
            }

            leftMaxIdx[i] = currLeftMaxIdx;

            st.push({heights[i], i});
        }

        while (!st.empty()) {
            st.pop();
        }

        int currRightMaxIdx;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }

            if (!st.empty()) {
                currRightMaxIdx = st.top().second - 1;
            } else {
                currRightMaxIdx = n - 1;
            }

            rightMaxIdx[i] = currRightMaxIdx;

            st.push({heights[i], i});
        }

        int res = 0;

        for (int i = 0; i < n; i++) {
            cout<<"LeftMax: "<<leftMaxIdx[i]<<" "<<"RightMax: "<<rightMaxIdx[i]<<endl;
            int length = rightMaxIdx[i] - leftMaxIdx[i] + 1;
            int breadth = heights[i];

            int area = length * breadth;

            res = max(res, area);
        }

        return res;
    }
};
