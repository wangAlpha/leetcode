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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::unordered_set<int> numbers = {head->val};
        auto pre = head;
        while (pre->next != nullptr) {
            auto cur = pre->next;
            const int val = cur->val;
            if (numbers.find(cur->val) != numbers.end()) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
            numbers.insert(val);
        }
        pre->next = nullptr;
        return head;
    }
};