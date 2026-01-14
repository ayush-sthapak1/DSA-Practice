// LeetCode 138: Copy List with Random Pointer
// Approach: HashMap (original node → cloned node)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;

        // 1st pass: create clone nodes
        Node* curr = head;
        while (curr != nullptr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 2nd pass: assign next and random pointers
        curr = head;
        while (curr != nullptr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};
