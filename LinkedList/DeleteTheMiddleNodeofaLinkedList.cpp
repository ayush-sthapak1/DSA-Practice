// LeetCode 2095: Delete the Middle Node of a Linked List
// Approach: Fast & Slow Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next;

        // Find node before the middle
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        slow->next = slow->next->next;
        return head;
    }
};
