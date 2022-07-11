class Solution {
public:
    string reverseWords(string& s) {
        stack<string> words;
        string ans;
        s.push_back(' ');
        size_t i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            while (s[i] == ' ') {
                ++i;
            }
            j = i;
            if (j == s.size()) break;
            while (s[j] != ' ') {
                ++j;
            }
            words.push(s.substr(i, j - i + 1));
            i = j;
            j += 1;
        } 
        while (!words.empty()) {
            auto word = words.top();
            words.pop();
            ans.append(word);
        }
        ans.pop_back();
        return ans;
    }
};