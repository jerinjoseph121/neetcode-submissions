class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> res;

        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;

            for (int count = 0; count < n; count++) {
                if (1 << count & i)
                    subset.push_back(nums[count]);
            }

            res.push_back(subset);
        }

        return res;
    }
};