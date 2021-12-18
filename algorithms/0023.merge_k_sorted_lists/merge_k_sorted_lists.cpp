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
 #include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pd(cmp);
        
        ListNode * merged_list = new ListNode{-1, nullptr};
        auto p = merged_list;

        for (auto &list : lists) {
            while (list != nullptr) {
                pd.push(list);
                list = list->next;
            }
        }     

        while (!pd.empty()) {
            const auto node = pd.top();
            node->next = nullptr;
            p->next = node;
            p = p->next;
            pd.pop();
        }
        return merged_list->next;
    }
};