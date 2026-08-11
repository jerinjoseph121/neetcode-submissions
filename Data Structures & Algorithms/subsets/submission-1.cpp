class Solution {
public:
    vector<vector<int>> res;
    void findSubsets(int idx, int &n, vector<int>& subArr, vector<int>& nums) {
        if (idx >= n) {
            res.push_back(subArr);
            return;
        }

        findSubsets(idx + 1, n, subArr, nums);

        subArr.push_back(nums[idx]);

        findSubsets(idx + 1, n, subArr, nums);

        subArr.pop_back();

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subArr;
        int n = nums.size();
        findSubsets(0, n, subArr, nums);
        return res;
    }
};
