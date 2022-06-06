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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummyHead(0, head);
        auto fast = &dummyHead;
        auto slow = &dummyHead;
        for (int i = 0; i < n && fast != nullptr; ++i) {
            fast = fast->next;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        auto next = slow->next;
        slow->next = slow->next->next;
        delete next;
        return dummyHead.next;
    }
};