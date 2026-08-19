class Solution {
public:
    vector<string> res;
    void getParenStrings(string &s, int &open, int &close, int &n) {
        if (close == n) {
            res.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            open++;

            getParenStrings(s, open, close, n);

            s.pop_back();
            open--;
        }

        if (close < open) {
            s.push_back(')');
            close++;

            getParenStrings(s, open, close, n);

            s.pop_back();
            close--;
        }
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s = "";

        int open = 0;
        int close = 0;

        getParenStrings(s, open, close, n);

        return res;
    }
};
