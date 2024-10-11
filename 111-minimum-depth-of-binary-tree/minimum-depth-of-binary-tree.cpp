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
    int rec(TreeNode* root)
    {
        if (root == nullptr) return 0;
        if(root && root->left == NULL && root->right == NULL) return 1;
        int lh=INT_MAX, rh=INT_MAX;
        if(root->left)
            lh = rec(root->left);
        if(root->right)
            rh = rec(root->right);
        return 1+min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        return rec(root);
    }
};