// LeetCode 206: Reverse Linked List
// Approach: Iterative pointer reversal using ptr1 and ptr2
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = nullptr;

        while (ptr1 != nullptr) {
            ListNode* nextNode = ptr1->next; // save next
            ptr1->next = ptr2;               // reverse link
            ptr2 = ptr1;                     // move ptr2
            ptr1 = nextNode;                 // move ptr1
        }
        return ptr2;
    }
};
