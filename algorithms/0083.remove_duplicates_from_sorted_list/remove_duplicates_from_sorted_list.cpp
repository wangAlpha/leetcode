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
    ListNode* deleteDuplicates(ListNode* head) {
        auto new_head = head;
        while (head != nullptr && head->next != nullptr) {
            if (head->val == head->next->val) {
                auto p = head->next;
                head->next = p->next;
                delete p; 
            } else {
                head = head->next;
            }
        }
        return new_head;
    }
};