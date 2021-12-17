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
        // vector<ListNode*> pd;
        for (auto &list : lists) {
            while (list != nullptr) {
                pd.push(list);
                list = list->next;
            }
        }
        if (pd.empty()) {
            return nullptr;
        }
        // make_heap(begin(pd), end(pd), cmp);
        ListNode * merged_list = pd.top();
        auto p = merged_list;
        pd.pop();
        while (!pd.empty()) {
            const auto node = pd.top();
            // node
            node->next = nullptr;
            p->next = node;
            p = p->next;
            pd.pop();
        }
        // for (size_t i = 0;i < merged_list.size() - 1; ++i) {
        //     merged_list[i]->next = merged_list[i+1];
        // }
        return merged_list;
    }
};