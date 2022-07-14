class Solution {
public:
    bool checkValidString(const string& s) {
        stack<size_t> leftStack;
        stack<size_t> asterStack;
        for (size_t i = 0; i < s.size(); ++i) {
            const char &c = s[i];
            if (c == '(') {
                leftStack.push(i);
            } else if (c == '*') {
                asterStack.push(i);
            } else {
                if (!leftStack.empty()) {
                    leftStack.pop();
                } else if (!asterStack.empty()) {
                    asterStack.pop();
                } else {
                    return false;
                }
            }
        }
        while (!leftStack.empty() && !asterStack.empty()) {
            auto leftIndex = leftStack.top(); leftStack.pop();
            auto asterIndex = asterStack.top(); asterStack.pop();
            if (leftIndex > asterIndex) {
                return false;
            }
        }
        return leftStack.empty();
    }
};