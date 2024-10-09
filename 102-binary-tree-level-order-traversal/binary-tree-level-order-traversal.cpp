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

 // time complexity-o(n) n no of nodes and space complexity is o(n) the worst case use of vector of vector and a queue.
class Solution {
public:
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> ans;
    //     if(root == NULL) return ans;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         int n = q.size();
    //         vector<int> v;
    //         for(int i=0;i<n;i++)
    //         {
    //              TreeNode* temp = q.front();
    //              q.pop();
    //             if(temp->left != NULL)
    //                 q.push(temp->left);
    //             if(temp->right != NULL)
    //                 q.push(temp->right);
    //              v.push_back(temp->val);
    //         }
    //         ans.push_back(v);
    //     }
    //     return ans;
    // }
    
    // Time Complexity - O(n)- each node is visited once.
    // Space Complexity: O(h) for the recursion stack (where h is the height of the tree) + O(n) for storing the result.
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        int cnt = 0;
        vector<vector<int>> result;
        rec(root, cnt, result);
        return result;
    }
};