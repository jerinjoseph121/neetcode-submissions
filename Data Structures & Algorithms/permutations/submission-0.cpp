class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int> isAdded;
    void findPermutations (vector<int> &comb, vector<int> &nums) {
        if (isAdded.size() == nums.size()) {
            res.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (isAdded[nums[i]])
                continue;
            isAdded[nums[i]]++;
            comb.push_back(nums[i]);
            findPermutations(comb, nums);
            comb.pop_back();
            isAdded.erase(nums[i]);
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> comb;

        findPermutations(comb, nums);

        return res;
    }
};
