class Solution {
public:
    bool findPartition(int idx, int currSum, int &n, int &sum, vector<int> &nums, vector<vector<int>> &dp) {
        if (idx >= n) {
            if (currSum == sum - currSum)
                return true;

            return false;
        }

        if (dp[idx][currSum] != - 1)
            return dp[idx][currSum];

        bool isPartition = false;

        isPartition |= findPartition(idx + 1, currSum + nums[idx], n, sum, nums, dp);
        isPartition |= findPartition(idx + 1, currSum, n, sum, nums, dp);

        return dp[idx][currSum] = isPartition;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2)
            return false;

        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));

        return findPartition(0, 0, n, sum, nums, dp);
    }
};
