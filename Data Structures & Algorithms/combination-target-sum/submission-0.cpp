class Solution {
public:
    vector<vector<int>> res;
    void findComb(int idx, vector<int> &combiArr, int &sum, vector<int> &nums, int &target) {
        if (sum >= target) {
            if (sum == target) {
                res.push_back(combiArr);
            }
            return;
        }

        if (idx >= nums.size())
            return;

        combiArr.push_back(nums[idx]);
        sum += nums[idx];

        findComb(idx, combiArr, sum, nums, target);

        sum -= nums[idx];
        combiArr.pop_back();

        findComb(idx + 1, combiArr, sum, nums, target);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> combiArr;
        int sum = 0;

        findComb(0, combiArr, sum, nums, target);

        return res;
    }
};
