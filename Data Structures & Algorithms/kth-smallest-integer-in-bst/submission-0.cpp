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

class Solution {
public:
    void traverseTree(TreeNode* root, vector<int> &values) {
        if (!root)
            return;

        traverseTree(root->left, values);
        values.push_back(root->val);
        traverseTree(root->right, values);

        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        traverseTree(root, values);

        return values[k - 1];
    }
};
