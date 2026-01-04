// LeetCode 142: Linked List Cycle II
// Approach: Floyd’s Cycle Detection Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No cycle
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        // Phase 2: Find cycle start
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // cycle entry point
    }
};
