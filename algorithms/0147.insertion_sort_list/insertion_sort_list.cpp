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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            auto node = head;
            head = head->next;
            auto tail = &dummy;
            for (; tail->next && tail->next->val < node->val; tail = tail->next) {}
            node->next = tail->next;
            tail->next = node;
        }
        return dummy.next;
    }
};