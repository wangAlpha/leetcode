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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = head;
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                swap(curr->val, prev->val);
                prev = prev->next;
            }
            curr = curr->next;
        }
        return head;
    }
};