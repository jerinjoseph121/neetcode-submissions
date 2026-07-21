class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int low = 0;
        int high = n - 1;

        int res = 0;

        while (low < high) {
            int area = min(heights[low], heights[high]) * (high - low);

            res = max(res, area);

            if (heights[low] < heights[high]) {
                low++;
            } else {
                high--;
            }
        }

        return res;
    }
};
