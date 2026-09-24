class Solution {
public:
    int maxRob(int idx, int &n, vector<int> &nums, vector<int> &dp) {
        if (idx >= n) {
            return 0;
        } 

        if (dp[idx] != -1)
            return dp[idx];

        int maxVal = nums[idx] + max(maxRob(idx + 2, n, nums, dp), maxRob(idx + 3, n, nums, dp));

        return dp[idx] = maxVal;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return max(maxRob(0, n, nums, dp), maxRob(1, n, nums, dp));
    }
};
