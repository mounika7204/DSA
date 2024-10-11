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
    TreeNode* prev = NULL;
    void rec(TreeNode* root, int& result)
    {
        if(root == NULL) return;
        rec(root->left, result);
        if(prev) result = min(result, abs(prev->val - root->val));
        prev = root;
        rec(root->right, result);
    }
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        rec(root, result);
        return result;
    }
};