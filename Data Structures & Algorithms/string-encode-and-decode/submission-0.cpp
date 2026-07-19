class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";

        for (auto &str : strs) {
            for (int i = 0; i < str.size(); i++) {
                int numVal = static_cast<int>(str[i]);
                encodedStr += to_string(numVal);
                encodedStr += " ";
            }

            encodedStr += "| ";
        }

        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrs;

        int n = s.size();
        int ptr = 0;

        string decodedStr = "";

        while (ptr < n) {
            while(ptr < n && s[ptr] == ' ') {
                ptr++;
            }

            int asciiNum = 0;

            while(ptr < n && s[ptr] >= '0' && s[ptr] <= '9') {
                asciiNum *= 10;
                asciiNum += (s[ptr] - '0');
                ptr++;
            }

            char ch;

            if (asciiNum) {
                ch = static_cast<char>(asciiNum);
                decodedStr += ch;
            }

            while(ptr < n && s[ptr] == ' ') {
                ptr++;
            }

            if (s[ptr] == '|') {
                decodedStrs.push_back(decodedStr);
                decodedStr = "";
                ptr++;
            }
        }

        return decodedStrs;
    }
};
