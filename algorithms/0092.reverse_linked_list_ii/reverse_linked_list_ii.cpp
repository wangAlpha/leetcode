/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) {
            return head;
        }
        auto dummyHead = ListNode(0, head);
        auto pre = &dummyHead;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        auto cur = pre->next;
        for (int i = 0; i < right - left; ++i) {
            auto next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyHead.next;
    }
};