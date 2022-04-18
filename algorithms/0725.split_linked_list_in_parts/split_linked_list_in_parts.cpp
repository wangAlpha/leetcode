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
    int getLength(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            ++len;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> lists(k, nullptr);
        const int len = getLength(head);
        const int n = len / k;
        int remainder = len % k;
        for (int i = 0; i < k && head != nullptr; ++i) {
            const int count = remainder > 0 ? n + 1 : n;
            lists[i] = head;
            --remainder;
            for (int j = 1; j < count && head != nullptr; ++j) {
                head = head->next;
            }
            auto curr = head;
            head = head->next;
            curr->next = nullptr;
        }
        return lists;
    }
};