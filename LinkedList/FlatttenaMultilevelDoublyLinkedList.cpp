// LeetCode 430: Flatten a Multilevel Doubly Linked List
// Approach: DFS (recursion)
// Time Complexity: O(n)
// Space Complexity: O(n) recursion stack

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        dfs(head);
        return head;
    }

private:
    Node* dfs(Node* curr) {
        Node* last = curr;

        while (curr) {
            if (curr->child) {
                // Flatten child
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                // Attach child list
                childTail->next = curr->next;
                if (curr->next)
                    curr->next->prev = childTail;

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                last = childTail;
                curr = childTail;   // jump to end of child
            } else {
                last = curr;
            }
            curr = curr->next;
        }
        return last;
    }
};
