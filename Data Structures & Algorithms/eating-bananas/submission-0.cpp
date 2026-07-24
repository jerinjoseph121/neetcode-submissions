class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = 1e9;

        while (low <= high) {
            int speed = (high - low) / 2 + low;

            int totalHrs = 0;

            for (int i = 0; i < n; i++) {
                totalHrs += ceil(piles[i] / (double)speed);
            }

            if (totalHrs <= h) {
                high = speed - 1;
            } else {
                low = speed + 1;
            }
        }

        return low;
    }
};
