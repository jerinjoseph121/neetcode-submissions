class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n, 0);

        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int temp = temperatures[i];

            while (!st.empty()) {
                int topTemp = st.top().first;
                int topIdx = st.top().second;
                if (temp > topTemp) {
                    res[topIdx] = i - topIdx;
                    st.pop();
                } else {
                    break;
                }
            }

            st.push({temp, i});
        }

        return res;
    }
};
