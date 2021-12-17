/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    size_t list_len(ListNode *first) {
        size_t len = 0;
        for (; first != nullptr; first = first->next) {
            len += 1;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        const size_t lenA = list_len(headA);
        const size_t lenB = list_len(headB);
        if (lenA > lenB) {
            for (size_t i = 0; i < lenA - lenB; ++i) {
                headA = headA->next;
            }
        }
        if (lenA < lenB) {
            for (size_t i = 0; i < lenB - lenA; ++i) {
                headB = headB->next;
            }
        }
        while (headA != nullptr) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};