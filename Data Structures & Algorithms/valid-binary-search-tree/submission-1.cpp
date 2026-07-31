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
    bool isBST(TreeNode* root, int lowLimit, int upLimit) {
        if (!root)
            return true;

        if (!(root->val > lowLimit && root->val < upLimit))
            return false;

        bool isLeftBST = isBST(root->left, lowLimit, root->val);
        bool isRightBST = isBST(root->right, root->val, upLimit);

        return isLeftBST && isRightBST;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MIN, INT_MAX);
    }
};
