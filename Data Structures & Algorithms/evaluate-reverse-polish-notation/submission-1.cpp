class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            string str = tokens[i];

            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                int c;

                switch(str[0]) {
                    case '+':
                        c = b + a;
                        break;
                    case '-':
                        c = b - a;
                        break;
                    case '*':
                        c = b * a;
                        break;
                    case '/':
                        c = b / a;
                        break;
                    default:
                }

                st.push(c);
            } else {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};
