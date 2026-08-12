class Solution {
public:
    vector<vector<int>> res;
    void findComb (int idx, vector<int> &combArr, vector<int> &nums, int &target) {
        if (target == 0) {
            res.push_back(combArr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            if (target - nums[i] < 0)
                break;

            combArr.push_back(nums[i]);

            target -= nums[i];

            findComb(i + 1, combArr, nums, target);

            target += nums[i];

            combArr.pop_back();
        }

        

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combArr;

        findComb(0, combArr, candidates, target);

        return res;
    }
};
