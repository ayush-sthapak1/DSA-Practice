// GFG: Children Sum Property in a Binary Tree (Easy)
// Link: https://www.geeksforgeeks.org/problems/children-sum-property-in-a-binary-tree/1
// Approach: Short-circuited recursive DFS check.
// Time: O(N) where N is the number of nodes in the binary tree.
// Space: O(H) auxiliary space for the recursion stack where H is the height of the tree.

class Solution {
private:
    bool isLeaf(Node* root) {
        return root->left == nullptr && root->right == nullptr;
    }

public:
    bool isSumProperty(Node *root) {
        // Base case: empty tree or leaf nodes always satisfy the property
        if (root == nullptr || isLeaf(root)) {
            return true;
        }

        int childSum = 0;
        if (root->left) childSum += root->left->data;
        if (root->right) childSum += root->right->data;

        // Current node must match child sum, and both subtrees must satisfy property
        if (root->data == childSum) {
            return isSumProperty(root->left) && isSumProperty(root->right);
        }

        return false;
    }
};
