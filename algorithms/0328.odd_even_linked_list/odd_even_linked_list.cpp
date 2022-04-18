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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        auto eventHead = head->next;
        auto event = eventHead;
        auto odd = head;
        while (event != nullptr && event->next != nullptr) {
            odd->next = event->next;
            odd = odd->next;
            event->next = odd->next;
            event = event->next;
        }
        odd->next = eventHead;
        return head;
    }
};