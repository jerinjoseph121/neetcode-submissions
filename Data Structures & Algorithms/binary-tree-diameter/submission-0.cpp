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
    int findMaxDia(TreeNode* root, int &res) {
        if (!root)
            return 0;

        int leftDepth = 0;
        int rightDepth = 0;

        if (root->left) {
            leftDepth++;
        }
        leftDepth += findMaxDia(root->left, res);

        if (root->right) {
            rightDepth++;
        }
        rightDepth += findMaxDia(root->right, res);

        res = max(res, leftDepth + rightDepth);

        return max(leftDepth, rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        findMaxDia(root, res);

        return res;
    }
};
