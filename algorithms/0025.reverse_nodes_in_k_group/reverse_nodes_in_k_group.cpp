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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode dummy(0, head);
        auto prev = &dummy, end = &dummy;
        while (end) {
            for (int i = 0; i < k && end; ++i) {
                end = end->next;
            }
            if (!end) {
                break;
            }
            auto start = prev->next;
            auto next = end->next;
            end->next = nullptr;
            prev->next = reverseList(prev->next);
            start->next = next;
            prev = start;
            
            end = prev;
        }
        return dummy.next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            auto node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
};