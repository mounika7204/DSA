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
        queue<TreeNode*> q;
        string s = "";
        if(root==NULL) return s;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL) s += "#";
            else 
            {
                s += to_string(curr->val);
                q.push(curr->left);
                q.push(curr->right);
            }
            s += ",";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        string str;
        if(str == "#") return NULL;
        getline(ss, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
    
            getline(ss, str, ',');
            if(str == "#") node->left = NULL;
            else 
            {
                TreeNode* node1 = new TreeNode(stoi(str));
                node->left = node1;
                q.push(node1);
            }
            
            getline(ss, str, ',');
            if(str == "#") node->right = NULL;
            else
            {
                TreeNode* node2 = new TreeNode(stoi(str));
                node->right = node2;
                q.push(node2);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));