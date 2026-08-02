/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string res = "";

        int nodeVal = root->val;

        res += to_string(nodeVal);

        res += " ( ";
        res += serialize(root->left);
        res += " ) ( ";
        res += serialize(root->right);
        res += " ) ";

        return res;
    }

    TreeNode* deserTree(queue<string> q) {
        if (q.empty())
            return nullptr;

        string seg = q.front();
        q.pop();

        // cout<<seg<<endl;

        TreeNode* node = new TreeNode(stoi(seg));

        int count;

        queue<string> leftQ;
        q.pop();
        count = 1;
        while (true) {
            if (q.front() == "(") {
                count++;
            } else if (q.front() == ")") {
                count--;
            }

            if (!count) {
                q.pop();
                break;
            }

            leftQ.push(q.front());
            q.pop();
        }

        node->left = deserTree(leftQ);

        queue<string> rightQ;
        q.pop();
        count = 1;
        while (true) {
            if (q.front() == "(") {
                count++;
            } else if (q.front() == ")") {
                count--;
            }

            if (!count) {
                q.pop();
                break;
            }

            rightQ.push(q.front());
            q.pop();
        }

        node->right = deserTree(rightQ);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;

        int n = data.size();

        int ptr = 0;

        // cout<<"Data: "<<data<<endl;

        while (ptr < n) {
            string seg = "";

            if (data[ptr] >= '0' && data[ptr] <= '9') {
                while (ptr < n && data[ptr] >= '0' && data[ptr] <= '9') {
                    seg += data[ptr];
                    ptr++;
                }
            } else if (data[ptr] == '(') {
                seg += data[ptr];
                ptr++;
            } else if (data[ptr] == ')') {
                seg += data[ptr];
                ptr++;
            } else {
                ptr++;
            }
            
            if (seg != "")
                q.push(seg);
        }

        // while(!q.empty()) {
        //     cout<<q.front()<<endl;
        //     q.pop();
        // }

        // return nullptr;

        return deserTree(q);
    }
};
