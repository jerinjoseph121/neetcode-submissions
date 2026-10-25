class Solution {
public:
    bool getWordBreak(int idx, string &s, vector<string>& wordDict, vector<int> &dp) {
        if (idx == s.size())
            return true;

        if (dp[idx] != -1) {
            return dp[idx];
        }

        string str = "";

        bool isWordBreak = false;

        for (int i = idx; i < s.size(); i++) {
            str += s[i];

            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {
                isWordBreak |= getWordBreak(i + 1, s, wordDict, dp);
            } 
        }

        return dp[idx] = isWordBreak;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<int> dp(n, -1);
        return getWordBreak(0, s, wordDict, dp);
    }
};
