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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }
        ListNode greaterHead(0);
        auto tail = &greaterHead;
        ListNode dummyHead(0, head);
        auto prev = &dummyHead;
        while (prev->next) {
            if (prev->next->val >= x) {
                auto next = prev->next;
                prev->next = next->next;
                next->next = nullptr;
                tail->next = next;
                tail = tail->next;
            } else {
                prev = prev->next;
            }
        }
        prev->next = greaterHead.next;
        return dummyHead.next;
    }
};