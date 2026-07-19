class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";

        for (auto &str : strs) {
            int n = str.size();

            encodedStr += to_string(n);
            encodedStr += "#";
            encodedStr += str;
        }

        return encodedStr;
    }

    vector<string> decode(string s) {
        int n = s.size();

        int ptr = 0;

        vector<string> res;

        while (ptr < n) {
            int size = 0;

            while (ptr < n && s[ptr] != '#') {
                int digit = s[ptr] - '0';
                size *= 10;
                size += digit;
                ptr++;
            }

            ptr++;

            string currStr = "";

            for (int i = 0; i < size; i++) {
                currStr += s[ptr++];
            }

            res.push_back(currStr);
        }

        return res;
    }
};
