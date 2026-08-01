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
    TreeNode* constructTree (int &idx, int low, int high, unordered_map<int, int> &mpp, vector<int>& preorder, vector<int>& inorder) {
        if (low > high)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        int mid = mpp[node->val];

        node->left = constructTree(idx, low, mid - 1, mpp, preorder, inorder);
        node->right = constructTree(idx, mid + 1, high, mpp, preorder, inorder);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;

        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        return constructTree(idx, 0, n - 1, mpp, preorder, inorder);
    }
};
