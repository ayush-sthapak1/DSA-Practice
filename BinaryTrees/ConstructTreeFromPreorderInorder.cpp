// LC 105: Construct Binary Tree from Preorder and Inorder Traversal (Medium)
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Approach: Recursion with inorder index mapping.
//           The first element of preorder is the root. We partition inorder around the root
//           to determine the sizes of left and right subtrees and recurse on their index bounds.
// Time: O(N) where N is the number of nodes in the tree (map lookup takes O(1)).
// Space: O(N) auxiliary space to store inorder index mappings + recursion stack.

class Solution {
private:
    TreeNode* subTree(unordered_map<int, int>& inMap, vector<int>& preorder, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = inMap[preorder[preStart]];
        int numsLeft = idx - inStart;

        root->left = subTree(inMap, preorder, preStart + 1, preStart + numsLeft, inStart, idx - 1);
        root->right = subTree(inMap, preorder, preStart + numsLeft + 1, preEnd, idx + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return subTree(inMap, preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
