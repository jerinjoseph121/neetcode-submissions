class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int res = 0;

        int l = 0;
        int r = 0;

        while (r < n) {
            int currProfit = prices[r] - prices[l];
            res = max(res, currProfit);
            if (prices[r] < prices[l]) {
                l++;
            } else {
                r++;
            }
        }

        return res;
    }
};
