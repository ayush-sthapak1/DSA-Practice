// LeetCode 160: Intersection of Two Linked Lists
// Approach: Two-pointer head switching
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists, switching heads on reaching null
        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        // Either intersection node or nullptr
        return ptrA;
    }
};
