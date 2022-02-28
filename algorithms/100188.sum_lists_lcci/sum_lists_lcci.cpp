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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* curr = new ListNode{-1, l1};
        ListNode* curr2 = new ListNode{-1, l2};
        int flag = 0;
        while (curr->next != nullptr && curr2->next != nullptr) {
            const int count = curr->next->val + curr2->next->val + flag;
            flag = count / 10;
            curr->next->val = count % 10;
            curr = curr->next;
            curr2 = curr2->next;
        }
//         1->nullptr
//         9->9->nullptr
        while (curr->next != nullptr) {
            const int count = curr->next->val + flag;
            flag = count/10;
            curr->next->val = (count % 10);
            curr = curr->next;
        }
        while (curr2->next != nullptr) {
            const int count = curr2->next->val + flag;
            flag = count/10;
            curr2->next->val = (count % 10);
            curr->next = curr2->next;
            
            curr2 = curr2->next;
            curr = curr->next;
        }
        while (curr->next == nullptr && curr2->next == nullptr && flag == 1) {
            curr->next = new ListNode(flag);
        } 
        return l1;
    }
};