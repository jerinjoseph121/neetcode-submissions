class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int> countMpp;
    void findComb (int idx, vector<int> &combArr, vector<int> &nums, int target) {
        if (target == 0) {
            res.push_back(combArr);
            return;
        }

        if (target < 0 || idx >= nums.size())
            return;

        if (countMpp[nums[idx]] && target - nums[idx] >= 0) {
            combArr.push_back(nums[idx]);

            countMpp[nums[idx]]--;

            findComb(idx, combArr, nums, target - nums[idx]);

            countMpp[nums[idx]]++;

            combArr.pop_back();
        }
        
        findComb(idx + 1, combArr, nums, target);

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums;
        for (auto &candidate: candidates) {
            if (!countMpp[candidate]) {
                nums.push_back(candidate);
            }

            countMpp[candidate]++;
        }

        vector<int> combArr;

        findComb(0, combArr, nums, target);

        return res;
    }
};
