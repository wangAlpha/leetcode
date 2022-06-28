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
    Solution(ListNode* head): head_(head), len_(lenOfList(head)) {
        srand (time(NULL));
    }
    
    int getRandom() {
        const int n = rand() % len_;
        auto node = head_;
        for (int i = 0; i < n; ++i) {
            node = node->next;
        }
        return node->val;
    }
    int lenOfList(ListNode* head) {
        int len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
        return len;
    }
private:
    ListNode* head_;
    int len_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */