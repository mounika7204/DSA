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
    priority_queue<int, vector<int>, greater<int>> pq;
    void rec(TreeNode* root)
    {
        if(root==nullptr) return;
        else pq.push(root->val);
        rec(root->left);
        rec(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        rec(root);
        for(int i=1;i<k;i++) pq.pop();
        return pq.top();
    }
};