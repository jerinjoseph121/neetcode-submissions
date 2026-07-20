class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            int reqNum = target - numbers[i];

            if (mpp[reqNum]) {
                return {mpp[reqNum], i + 1};
            }

            mpp[numbers[i]] = i + 1;
        }

        return {-1, -1};
    }
};
