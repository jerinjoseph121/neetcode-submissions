class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        int n = nums.size();

        vector<int> res;

        for (int i = 0; i < n; i++) {
            int reqVal = target - nums[i];

            if (mpp.find(reqVal) != mpp.end()) {
                res.push_back(mpp[reqVal]);
                res.push_back(i);
                break;
            }
            mpp[nums[i]] = i;
        }

        return res;
    }
};
