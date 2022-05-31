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
    ListNode* reverseList(ListNode* head) {
        ListNode dummyHead(0);
        auto new_node = &dummyHead;
        while (head) {
            auto node = head;
            head = head->next;
            node->next = new_node->next;
            new_node->next = node;
        }
        return dummyHead.next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int sign = 0;
        ListNode dummyHead(0);
        auto new_node = &dummyHead;
        while (l1 || l2) {
            int val = 0;
            if (l1) {
                val = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            val += sign;
            sign = val / 10;
            val %= 10;
            auto node = new ListNode(val, new_node->next);
            new_node->next = node;
        }
        if (sign > 0) {
            auto node = new ListNode(sign, new_node->next);
            new_node->next = node;
        }
        return dummyHead.next;
    }
};