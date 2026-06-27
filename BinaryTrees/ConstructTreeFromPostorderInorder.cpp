// LC 106: Construct Binary Tree from Postorder and Inorder Traversal (Medium)
// Approach: Recursion with inorder index mapping.
//           The last element of postorder is the root. We partition inorder around the root
//           to determine the sizes of left and right subtrees and recurse on their index bounds.
// Time: O(N) where N is the number of nodes in the tree (map lookup takes O(1)).
// Space: O(N) auxiliary space to store inorder index mappings + recursion stack.

class Solution {
private:
    TreeNode* subTree(unordered_map<int, int>& inMap, vector<int>& postorder, int postStart, int postEnd, int inStart, int inEnd) {
        if (postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = inMap[postorder[postEnd]];
        int numsLeft = idx - inStart;

        root->right = subTree(inMap, postorder, postStart + numsLeft, postEnd - 1, idx + 1, inEnd);
        root->left = subTree(inMap, postorder, postStart, postStart + numsLeft - 1, inStart, idx - 1);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return subTree(inMap, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
};
