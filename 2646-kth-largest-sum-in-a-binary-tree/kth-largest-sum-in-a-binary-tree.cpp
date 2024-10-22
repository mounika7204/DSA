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
    void rec(TreeNode* root, int k, vector<vector<long long int>>& v, int i)
    {
        if(root == NULL) return;
        if (i >= v.size()) {
            v.push_back(vector<long long int>());
        }
        v[i].push_back(root->val);
        rec(root->left,k,v,i+1);
        rec(root->right,k,v,i+1);
        return;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL) return 0;
        vector<vector<long long int>> v;
        rec(root, k, v, 0);
       priority_queue<long long int> pq;
        for(auto vec : v)
        {
            long long int sum = 0;
            for(int i=0;i<vec.size();i++)
            {
                sum += vec[i];
            }
            pq.push(sum);
        }
        if(pq.size() < k) return -1;
        while(--k > 0) pq.pop();
        return pq.top();
    }
};