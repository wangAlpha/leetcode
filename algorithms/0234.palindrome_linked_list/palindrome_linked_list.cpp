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
    int getListLength(ListNode* head) {
        int len = 0;
        for (; head != nullptr; head = head->next) {
            ++len;
        }
        return len;
    }
    ListNode* reveseNodes(ListNode* head) {
        ListNode* new_head = nullptr;
        while (head != nullptr) {
            auto p = head;
            head = head->next;
            p->next = new_head;
            new_head = p;
        }
        return new_head;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        const int len = getListLength(head);
        auto node = head;
        for (int i = 0; i < (len + 1)/2; ++i) {
            head = head->next;
        }
        head = reveseNodes(head);
        while (head != nullptr) {
            if (head->val != node->val) {
                return false;
            }
            head = head->next;
            node = node->next;
        }
        return true;
    }
};