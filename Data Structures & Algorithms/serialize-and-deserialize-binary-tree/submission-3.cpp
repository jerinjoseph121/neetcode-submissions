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
            return "N,";

        string res = "";

        res += to_string(root->val) + ",";

        res += serialize(root->left);

        res += serialize(root->right);

        return res;
    }

    TreeNode* constructTree(int &idx, vector<string> &valArr) {
        if (idx >= valArr.size())
            return nullptr;

        if (valArr[idx] == "N") {
            idx++;
            return nullptr;
        }
            
        TreeNode* node = new TreeNode(stoi(valArr[idx++]));

        node->left = constructTree(idx, valArr);
        node->right = constructTree(idx, valArr);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();

        int ptr = 0;

        // cout<<"Data: "<<data<<endl;

        vector<string> valArr;

        while (ptr < n) {
            string valStr = "";
            if (data[ptr] >= '0' && data[ptr] <= '9') {
                while (data[ptr] >= '0' && data[ptr] <= '9') {
                    valStr += data[ptr];
                    ptr++;
                }
                valArr.push_back(valStr);
            } else if (data[ptr] == 'N') {
                valStr += data[ptr];
                valArr.push_back(valStr);
                ptr++;
            }

            ptr++;
        }

        int idx = 0;

        return constructTree(idx, valArr);
    }
};
