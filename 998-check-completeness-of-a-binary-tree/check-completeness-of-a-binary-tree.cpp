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
    int numOfNodes(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + numOfNodes(root->left) + numOfNodes(root->right);
    }
    bool rec(int i, TreeNode* root, int n)
    {
        if(root == NULL) return true;
        if(i >= n) return false;

        bool isLeftValid = rec(2*i+1, root->left, n);
        bool isRightValid = rec(2*i+2, root->right, n);

        return isLeftValid && isRightValid;
    }
    bool isCompleteTree(TreeNode* root) {
        int n  = numOfNodes(root);
        return rec(0, root, n);   
    }
};