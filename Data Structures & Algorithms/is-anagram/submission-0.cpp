class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n != m)
            return false;
        
        vector<int> mpp(26, 0);

        for (int i = 0; i < n; i++) {
            int sVal = s[i] - 'a';
            int tVal = t[i] - 'a';

            mpp[sVal]++;
            mpp[tVal]--;
        }

        for (int i = 0; i < 26; i++) {
            if (mpp[i])
                return false;
        }

        return true;
    }
};
