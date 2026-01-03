// LeetCode 206: Reverse Linked List
// Approach: Recursion
// Time Complexity: O(n)
// Space Complexity: O(n) (recursion stack)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // Reverse rest of the list
        ListNode* newHead = reverseList(head->next);

        // Fix current node
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
