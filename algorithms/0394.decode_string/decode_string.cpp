class Solution {
public:
    string decodeString(const string& s) {
        string cur_str;
        int number = 0;

        stack<int> numbers;
        stack<string> strings;
        
        for (const char& c: s) {
            if (c == '[') {
                numbers.push(number);
                strings.push(cur_str);
                cur_str.clear();
                number = 0;
            } else if (c == ']') {
                auto n = numbers.top(); numbers.pop();
                auto str = strings.top(); strings.pop();
                for (int i = 0; i < n; ++i) {
                    str.append(cur_str);
                }
                cur_str = str;
            } else if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else {
                cur_str.push_back(c);
            }
        }
        return cur_str;
    }
};