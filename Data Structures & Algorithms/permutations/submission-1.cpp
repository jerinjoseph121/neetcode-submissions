class Solution {
public:
    vector<vector<int>> res;
    vector<bool> isPicked;
    void findPermutations (int &count, vector<int> &comb, vector<int> &nums) {
        if (count == nums.size()) {
            res.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (isPicked[i])
                continue;
            isPicked[i] = true;
            count++;
            comb.push_back(nums[i]);
            findPermutations(count, comb, nums);
            comb.pop_back();
            count--;
            isPicked[i] = false;
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        isPicked = vector<bool> (n, false);
        vector<int> comb;

        int count = 0;

        findPermutations(count, comb, nums);

        return res;
    }
};
