class Solution {
public:
    int maxRob(int idx, int &n, vector<int> &nums, bool isFirstTaken, vector<vector<int>> &dp) {
        if (idx >= n)
            return 0;

        if (idx == n - 1) {
            if (isFirstTaken)
                return 0;
            else
                return nums[idx];
        }

        if (dp[idx][isFirstTaken] != -1)
            return dp[idx][isFirstTaken];

        int maxRobIfTaken;
        if (idx == 0) {
            maxRobIfTaken = nums[idx] + maxRob(idx + 2, n, nums, true, dp);
        }  else {
             maxRobIfTaken = nums[idx] + maxRob(idx + 2, n, nums, isFirstTaken, dp);
        }

        int maxRobIfNotTaken = maxRob(idx + 1, n, nums, isFirstTaken, dp);

        return dp[idx][isFirstTaken] = max(maxRobIfTaken, maxRobIfNotTaken);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));

        return maxRob(0, n, nums, false, dp);
    }
};
