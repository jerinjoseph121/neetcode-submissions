class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int low = 0;
        int high = n - 1;

        while (low < high) {
            while(low < high) {
                if (!(s[low] >= 'a' && s[low] <= 'z') &&
                    !(s[low] >= 'A' && s[low] <= 'Z') &&
                    !(s[low] >= '0' && s[low] <= '9')) {
                    low++;
                } else {
                    break;
                }
            }

            while(low < high) {
                if (!(s[high] >= 'a' && s[high] <= 'z') &&
                    !(s[high] >= 'A' && s[high] <= 'Z') && 
                    !(s[high] >= '0' && s[high] <= '9')) {
                    high--;
                } else {
                    break;
                }
            }

            if (!(low < high)) {
                break;
            }

            char lowCh = s[low];

            if (s[low] >= 'A' && s[low] <= 'Z') {
                lowCh = lowCh - 'A' + 'a';
            }

            char highCh = s[high];

            if (s[high] >= 'A' && s[high] <= 'Z') {
                highCh = highCh - 'A' + 'a';
            }

            if (lowCh != highCh)
                return false;

            low++;
            high--;
        }

        return true;
    }
};
