class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int currCount = 0;
        int nextCount = 1;
        int nextNextCount = 0;

        for (int i = n - 1; i >= 0; i--) {
            int currDigit = s[i] - '0';

            currCount = 0;

            if (!currDigit) {
                nextNextCount = nextCount;
                nextCount = currCount;
                continue;
            }
                
            currCount += nextCount;

            if (i + 1 < n) {
                int nextDigit = s[i + 1] - '0';

                currDigit = currDigit * 10 + nextDigit;

                if (currDigit <= 26) {
                    currCount += nextNextCount;
                }
            }

            nextNextCount = nextCount;
            nextCount = currCount;
        }

        return currCount;
    }
};
