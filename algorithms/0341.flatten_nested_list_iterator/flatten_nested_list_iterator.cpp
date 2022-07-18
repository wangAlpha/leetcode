/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    using iter = vector<NestedInteger>::iterator;
    stack<pair<iter, iter>> stk_; 
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
       stk_.emplace(nestedList.begin(), nestedList.end()); 
    }
    
    int next() {
       return stk_.top().first++->getInteger(); 
    }
    
    bool hasNext() {
        while (!stk_.empty()) {
            auto &p = stk_.top();
            if (p.first == p.second) {
                stk_.pop();
                continue;
            }
            if (p.first->isInteger()){
                return true;
            }
            auto &lst = p.first++->getList();
            stk_.emplace(lst.begin(), lst.end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */