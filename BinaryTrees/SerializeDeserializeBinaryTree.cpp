// LC 297: Serialize and Deserialize Binary Tree (Hard)
// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Approach: BFS (Level Order Traversal) using queue and stringstream.
//           Null nodes are represented by "#" and nodes are delimited by commas.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(N) auxiliary space to store queue elements and serialization string tokens.

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string data = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (!curr) {
                data += "#,";
            } else {
                data += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // Reconstruct Left Child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    curr->left = new TreeNode(stoi(str));
                    q.push(curr->left);
                }
            }
            
            // Reconstruct Right Child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    curr->right = new TreeNode(stoi(str));
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
