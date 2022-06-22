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
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode dummy(0);
        auto tail = &dummy;
        int flag = 0;
        while (l1 || l2) {
            int sum = flag;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            flag = sum / 10;
        }
        if (flag != 0) {
            tail->next = new ListNode(flag);
        }
        return dummy.next;
    }
};