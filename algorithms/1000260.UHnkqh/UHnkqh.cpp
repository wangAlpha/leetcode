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
        ListNode dummyHead(-1);
        auto new_node = &dummyHead;
        while (head != nullptr) {
            auto node = head;
            head = head->next;
            node->next = new_node->next;
            new_node->next = node;
        }
        return dummyHead.next;
    }
};