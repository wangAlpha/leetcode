class Solution {
public:
    string removeDuplicates(const string &s) {
        string ss;
        for (const char &c: s) {
            if (ss.empty() || ss.back() != c) {
                ss.push_back(c);
            } else {
                ss.pop_back();
            }
        }
        return ss;
    }
};