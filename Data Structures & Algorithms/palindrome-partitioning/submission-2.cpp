class Solution {
public:
    vector<vector<string>> res;

    bool isPalindrome(string &str) {
        int l = 0;
        int r = str.size() - 1;

        while (l < r) {
            if (str[l] != str[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void findPartitions(int ptr, vector<string> &split, string &s) {
        if (ptr == s.size()) {
            res.push_back(split);
            return;
        }

        string str = "";

        for (int i = ptr; i < s.size(); i++) {
            str += s[i];
            if (isPalindrome(str)) {
                split.push_back(str);
                findPartitions(i + 1, split, s);
                split.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        vector<string> split;

        findPartitions(0, split, s);
        
        return res;
    }
};
