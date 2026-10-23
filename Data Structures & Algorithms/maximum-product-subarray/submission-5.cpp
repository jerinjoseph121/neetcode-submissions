class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxVal = 1;
        int minVal = 1;

        int res = nums[0];

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                maxVal = 1;
                minVal = 1;
                res = max(res, 0);
                continue;
            }

            int currMaxVal = max(nums[i] * maxVal, nums[i] * minVal);
            int currMinVal = min(nums[i] * maxVal, nums[i] * minVal);

            maxVal = max(currMaxVal, nums[i]);

            minVal = min(currMinVal, nums[i]);

            res = max(res, maxVal);
        }

        return res;
    }
};
