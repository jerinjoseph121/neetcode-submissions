class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false;
                
                char openCh = st.top();

                if ((openCh == '(' && ch == ')') ||
                    (openCh == '{' && ch == '}') ||
                    (openCh == '[' && ch == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty() ? true : false;
    }
};
