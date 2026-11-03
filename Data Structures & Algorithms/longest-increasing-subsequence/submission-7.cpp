class Solution {
public:
    int getMaxLen(int idx, int &n, vector<int> &nums, vector<int> &dp) {
        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int maxLen = 1;

        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                maxLen = max(maxLen, 1 + getMaxLen(i, n, nums, dp));
            }
        }

        return dp[idx] = maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        int res = 0;

        for (int i = 0; i < n; i++) {
            res = max(res, getMaxLen(i, n, nums, dp));
        }

        return res;
    }
};
