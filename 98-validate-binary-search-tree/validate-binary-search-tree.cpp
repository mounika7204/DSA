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
    bool isBst(TreeNode* root, long long int lower, long long int upper)
    {
        if(root == NULL) return true;
        if(root->val <= lower or root->val >= upper) return false;
        return isBst(root->left, lower, root->val) && isBst(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return isBst(root, LONG_MIN, LONG_MAX);
    }
};