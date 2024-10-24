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
    void rec(TreeNode* root, int cnt, vector<int>& result)
    {
        if(root==NULL) return;
        if(cnt >= result.size()) result.push_back(root->val);
        rec(root->right, cnt+1, result);
        rec(root->left, cnt+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
       int cnt = 0;
       vector<int> result;
       rec(root, cnt, result);
       return result;
    }
};