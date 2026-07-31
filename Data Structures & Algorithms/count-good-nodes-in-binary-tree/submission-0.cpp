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
    int findGoodNodes(TreeNode* root, int currMax) {
        if (!root)
            return 0;

        int count = 0;

        if (root->val >= currMax)
            count++;

        currMax = max(currMax, root->val);

        count += findGoodNodes(root->left, currMax);
        count += findGoodNodes(root->right, currMax);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return findGoodNodes(root, INT_MIN);
    }
};
