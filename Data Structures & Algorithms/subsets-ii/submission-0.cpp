class Solution {
public:
    set<vector<int>> res;
    void findSubsets(int idx, vector<int> &subset, vector<int> &nums) {
        if (idx >= nums.size()) {
            res.insert(subset);
            return;
        }

        subset.push_back(nums[idx]);

        findSubsets(idx + 1, subset, nums);

        subset.pop_back();

        while (idx + 1 < nums.size() && nums[idx] == nums[idx] + 1) {
            idx++;
        }

        findSubsets(idx + 1, subset, nums);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> subset;

        findSubsets(0, subset, nums);

        return vector<vector<int>>(res.begin(), res.end());
    }
};
