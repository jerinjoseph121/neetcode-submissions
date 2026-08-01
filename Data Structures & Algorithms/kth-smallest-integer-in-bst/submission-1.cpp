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
    int findKTree(TreeNode* root, int &count, int &k) {
        if (!root)
            return -1;

        int valLeft = findKTree(root->left, count, k);
        if (valLeft != -1)
            return valLeft;

        if (count == k)
            return root->val;
        
        count++;
        int valRight = findKTree(root->right, count, k);
        if (valRight != -1)
            return valRight;

        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 1;
        return findKTree(root, count, k);
    }
};
