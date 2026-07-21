class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> res;

        int i = 0;

        while (i < n) {
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum < 0) {
                    low++;
                    while (low < high && nums[low] == nums[low - 1]) {
                        low++;
                    }
                } else if (sum > 0){
                    high--;
                    while (low < high && nums[high] == nums[high + 1]) {
                        high--;
                    }
                } else {
                    res.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    while (low < high && nums[low] == nums[low - 1]) {
                        low++;
                    }
                }
            }

            i++;
            while (i < n && nums[i] == nums[i - 1]) {
                i++;
            }
        }

        return res;
    }
};
