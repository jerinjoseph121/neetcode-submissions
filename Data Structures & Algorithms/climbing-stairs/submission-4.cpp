class Solution {
public:
    int climbStairs(int n) {
        int dpFirst = 1;
        int dpSecond = 0;

        for (int i = n - 1; i >= 0; i--) {
            int temp = 0;
            temp += dpFirst;
            temp += dpSecond;

            dpSecond = dpFirst;
            dpFirst = temp;
        }
        
        return dpFirst;
    }
};
