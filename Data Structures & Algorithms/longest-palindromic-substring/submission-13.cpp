class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int maxL = 0;
        int maxR = 0;

        for (int mid = 0; mid < n; mid++) {
            int currL = mid;
            int currR = mid;


            while (currL >= 0 && currR < n && s[currL] == s[currR]) {
                if (currR - currL + 1 > maxR - maxL + 1) {
                    maxL = currL;
                    maxR = currR;
                }
                currL--;
                currR++;
            }

            currL = mid;
            currR = mid + 1;

            while (currL >= 0 && currR < n && s[currL] == s[currR]) {
                if (currR - currL + 1 > maxR - maxL + 1) {
                    maxL = currL;
                    maxR = currR;
                }
                currL--;
                currR++;
            }
        }

        return s.substr(maxL, maxR - maxL + 1);
    }
};
