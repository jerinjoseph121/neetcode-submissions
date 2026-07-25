class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int res = INT_MAX;

        while (low <= high) {
            if (nums[low] < nums[high]) {
                res = min(res, nums[low]);
                break;
            }

            int mid = (high - low) / 2 + low;

            res = min(res, nums[mid]);

            if (nums[mid] >= nums[low]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 

        return res;
    }
};
