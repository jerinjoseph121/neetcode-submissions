class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int size = n * m;

        int low = 0;
        int high = size - 1;

        while (low <= high) {
            int mid = (high - low) / 2 + low;

            int r = mid / m;
            int c = mid % m;

            if (matrix[r][c] < target) {
                low = mid + 1;
            } else if (matrix[r][c] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
