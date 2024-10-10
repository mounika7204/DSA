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
    void rec(TreeNode* root, int val, int depth, int cnt)
    {
        if(root == NULL) return;
        if(cnt == depth-1){
            TreeNode* node1 = new TreeNode(val);
            node1->left = root->left;
            TreeNode* node2 = new TreeNode(val);
            node2->right = root->right;
            root->left = node1;
            root->right = node2;
        }
        cnt++;
        rec(root->left, val, depth, cnt);
        rec(root->right, val, depth, cnt);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        rec(root, val, depth, 1);
        return root;
    }
};