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
    int res;
    int findMaxPath(TreeNode* root) {
        if (!root)
            return 0;

        int maxVal = 0;

        int maxLeftPath = findMaxPath(root->left);
        maxVal = max(maxVal, root->val + maxLeftPath);
        int maxRightPath = findMaxPath(root->right);
        maxVal = max(maxVal, root->val + maxRightPath);

        res = max(res, root->val + maxLeftPath + maxRightPath);

        return maxVal;        
    }

    int maxPathSum(TreeNode* root) {
        res = root->val;

        findMaxPath(root);

        return res;
    }
};
