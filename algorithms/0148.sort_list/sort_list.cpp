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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto mid = middleOfNode(head);
        auto rightNode = mid->next;
        mid->next = nullptr;

       auto left = sortList(head);
       auto right = sortList(rightNode);
       return mergeList(left, right); 
    }
    
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode dummy(0);
        auto curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 == nullptr ? l2 : l1;
        return dummy.next;
    }
    ListNode* middleOfNode(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode dummy(0, head);
        auto slow = &dummy, fast = &dummy;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};