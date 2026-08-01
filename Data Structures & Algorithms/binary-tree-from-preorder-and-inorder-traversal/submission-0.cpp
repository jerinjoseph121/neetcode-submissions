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
    TreeNode* contructTree (int &idx, int low, int high, vector<int>& preorder, vector<int>& inorder) {
        if (low > high)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;

        int mid = low;

        for (int i = low; i <= high; i++) {
            if (inorder[i] == node->val) {
                mid = i;
                break;
            }
        }

        node->left = contructTree(idx, low, mid - 1, preorder, inorder);
        node->right = contructTree(idx, mid + 1, high, preorder, inorder);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return contructTree(idx, 0, n - 1, preorder, inorder);
    }
};
