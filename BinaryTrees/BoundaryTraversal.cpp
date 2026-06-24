// GFG: Boundary Traversal of Binary Tree (Medium)
// Approach: Three-stage traversal: Left Boundary (non-leaf) -> Leaves (DFS) -> Right Boundary (non-leaf, reversed)
// Time: O(N) where N is the number of nodes in the binary tree
// Space: O(H) recursion stack space where H is the tree height

#include <vector>
using namespace std;

#ifndef NODE_DEFINITION
#define NODE_DEFINITION
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
#endif

class Solution {
private:
    bool isLeaf(Node* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    void leftBoundary(Node* curr, vector<int>& result) {
        if (curr == nullptr || isLeaf(curr)) return;
        
        result.push_back(curr->data);
        if (curr->left != nullptr) {
            leftBoundary(curr->left, result);
        } else {
            leftBoundary(curr->right, result);
        }
    }

    void leafNodes(Node* curr, vector<int>& result) {
        if (curr == nullptr) return;
        if (isLeaf(curr)) {
            result.push_back(curr->data);
            return;
        }
        leafNodes(curr->left, result);
        leafNodes(curr->right, result);
    }

    void rightBoundary(Node* curr, vector<int>& result) {
        if (curr == nullptr || isLeaf(curr)) return;
        
        if (curr->right != nullptr) {
            rightBoundary(curr->right, result);
        } else {
            rightBoundary(curr->left, result);
        }
        result.push_back(curr->data);
    }

public:
    vector<int> boundaryTraversal(Node *root) {
        if (root == nullptr) return {};
        vector<int> result;
        
        // 1. Add Root if it is not a leaf node
        if (!isLeaf(root)) {
            result.push_back(root->data);
        }
        
        // 2. Add Left Boundary (excluding leaf nodes)
        leftBoundary(root->left, result);
        
        // 3. Add Leaf Nodes
        leafNodes(root, result); 
        
        // 4. Add Right Boundary (excluding leaf nodes, in reverse order)
        rightBoundary(root->right, result);
        
        return result;
    }
};
