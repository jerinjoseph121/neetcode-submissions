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
    int preIdx = 0;
    int inIdx = 0;
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int limit) {
        if (preIdx >= preorder.size())
            return nullptr;

        if (inorder[inIdx] == limit) {
            inIdx++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[preIdx++]);
        node->left = constructTree(preorder, inorder, node->val);
        node->right = constructTree(preorder, inorder, limit);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, inorder, INT_MAX);
    }
};
