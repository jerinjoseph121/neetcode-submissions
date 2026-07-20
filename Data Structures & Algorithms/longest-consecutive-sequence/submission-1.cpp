class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int res = 0;

        for (int i = 0; i < n; i++) {
            if (mpp[nums[i]]) {
                continue;
            }

            int leftLen = mpp[nums[i] - 1];
            int rightLen = mpp[nums[i] + 1];

            int totalLen = leftLen + rightLen + 1;

            mpp[nums[i]] = totalLen;
            mpp[nums[i] - leftLen] = totalLen;
            mpp[nums[i] + rightLen] = totalLen;

            res = max(res, totalLen);
        }

        return res;
    }
};
