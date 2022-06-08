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
    int lengthOfList(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k <= 0) {
            return head;
        }
        const int len = lengthOfList(head);
        // if (len <= k) {
        //     return head;
        // }
        k %= len;
        auto tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = head;
        for (int i = 0; i < len - k; ++i) {
            head = head->next;
            tail = tail->next;
        }
        tail->next = nullptr;
        return head;
    }
};