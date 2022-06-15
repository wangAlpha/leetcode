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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        auto mid_list = midOfList(head);
        auto l1 = head;
        auto l2 = reverseList(mid_list->next);
        mid_list->next = nullptr;
        while (l1 && l2) {
            auto next1 = l1->next;
            auto next2 = l2->next;
            l1->next = l2;
            l1 = next1;
            l2->next = l1;
            l2 = next2;
        }
    }
    ListNode* midOfList(ListNode* head) {
        auto dummy = ListNode(0, head);
        auto fast = &dummy, slow = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        auto dummy = ListNode(0);
        auto prev = &dummy;
        while (head) {
            auto node = head;
            head = head->next; 
            node->next = prev->next;
            prev->next = node;
        }
        return dummy.next;
    }
};