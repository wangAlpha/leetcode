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
    int lengthOfList(ListNode *head) {
        int len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = lengthOfList(headA);
        int lenB = lengthOfList(headB);
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }
        for (int i = 0; i < lenA - lenB; ++i) {
            headA = headA->next;
        }
        while (headA && headB) {
            if (headA == headB) {
                break;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};