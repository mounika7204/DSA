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
  void rec(TreeNode* root, int cnt, vector<vector<int>>& result)
    {
        if(root == NULL) return;
        if(result.size() <= cnt) result.push_back(vector<int>());
        result[cnt].push_back(root->val);
        cnt++;
        rec(root->left, cnt, result);
        rec(root->right, cnt, result);
        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        int cnt = 0;
        vector<vector<int>> result;
        rec(root, cnt, result);
        reverse(result.begin(), result.end());
        return result;
    }
};