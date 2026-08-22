class Solution {
public:
    unordered_map<int, vector<char>> mpp;

    vector<string> res;

    void findCombs(int ptr, string &comb, string &digits) {
        if (ptr == digits.size()) {
            if (comb.size())
                res.push_back(comb);
            return;
        }

        for (auto &ch : mpp[digits[ptr] - '0']) {
            comb += ch;

            findCombs(ptr + 1, comb, digits);

            comb.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        mpp[2] = {'a', 'b', 'c'};
        mpp[3] = {'d', 'e', 'f'};
        mpp[4] = {'g', 'h', 'i'};
        mpp[5] = {'j', 'k', 'l'};
        mpp[6] = {'m', 'n', 'o'};
        mpp[7] = {'p', 'q', 'r', 's'};
        mpp[8] = {'t', 'u', 'v'};
        mpp[9] = {'w', 'x', 'y', 'z'};

        string comb = "";

        findCombs(0, comb, digits);

        return res;
    }
};
