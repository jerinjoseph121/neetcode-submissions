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
    int findDepth(TreeNode* root, bool &res) {
        if (!root)
            return 0;

        int leftDepth = 1 + findDepth(root->left, res);
        int rightDepth = 1 + findDepth(root->right, res);

        if (abs(leftDepth - rightDepth) > 1)
            res = false;

        return max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;

        findDepth(root, res);

        return res;
    }
};
