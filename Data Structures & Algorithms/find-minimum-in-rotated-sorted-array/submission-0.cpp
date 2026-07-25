class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int minVal = INT_MAX;

        for (int i = 0; i < n; i++) {
            minVal = min(minVal, nums[i]);
        }

        return minVal;
    }
};
