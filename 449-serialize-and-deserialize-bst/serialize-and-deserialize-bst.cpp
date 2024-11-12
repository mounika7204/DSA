/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    int i=0;
    TreeNode* deserialize(string data) {
        if(i>=data.size()) return NULL;
        string t = "";
        while(data[i] != ',') t += data[i++];
        i++;
        if(t == "null") return NULL;
        TreeNode* node = new TreeNode(stoi(t));
        node->left = deserialize(data);
        node->right = deserialize(data);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;