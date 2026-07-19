class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftProd(n);
        vector<int> rightProd(n);

        int prod = 1;

        for (int i = 0; i < n; i++) {
            prod *= nums[i];
            leftProd[i] = prod;
        }

        prod = 1;

        for (int i = n - 1; i >= 0; i--) {
            prod *= nums[i];
            rightProd[i] = prod;
        }

        vector<int> res;

        for (int i = 0; i < n; i++) {
            int leftProdVal = 1;
            int rightProdVal = 1;

            if (i - 1 >= 0) {
                leftProdVal = leftProd[i - 1];
            }

            if (i + 1 < n) {
                rightProdVal = rightProd[i + 1];
            }

            res.push_back(leftProdVal * rightProdVal);
        }

        return res;
    }
};
