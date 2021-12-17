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
    void palindrome_iter(ListNode *&first, ListNode *last, bool &result) {
        // if (first == last) return;
        if (last->next != nullptr) {
            // last = last->next;
            palindrome_iter(first, last->next, result);
        }
        result &= (first->val == last->val);
        first = first->next;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        bool result = true;
        palindrome_iter(head, head, result);
        return result;
    }
};