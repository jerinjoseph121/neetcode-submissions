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
    bool isMatch(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        if (!root)
            return false;

        if (!subRoot)
            return false;

        if (root->val != subRoot->val)
            return false;

        bool isLeftMatch = isMatch(root->left, subRoot->left);
        bool isRightMatch = isMatch(root->right, subRoot->right);

        return isLeftMatch && isRightMatch;
    }
    void checkSub(TreeNode* root, TreeNode* subRoot, bool &res) {
        if (!root)
            return;

        checkSub(root->left, subRoot, res);
        checkSub(root->right, subRoot, res);

        if (isMatch(root, subRoot))
            res = true;

        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res = false;

        checkSub(root, subRoot, res);

        return res;
    }
};
