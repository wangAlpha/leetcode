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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        while (l1 != nullptr) {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2);
            l2 = l2->next;
        }
        ListNode dummyHead(0);
        int value = 0;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                value += s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                value += s2.top()->val;
                s2.pop();
            }
            dummyHead.next = new ListNode(value % 10, dummyHead.next);
            value /= 10;
        }
        if (value != 0) {
            dummyHead.next = new ListNode(value, dummyHead.next);
        }
        return dummyHead.next;
    }
};