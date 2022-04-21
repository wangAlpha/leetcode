class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        while (left < s.size() && s[left] == ' ') ++left;
        while (right > 0 && s[right] == ' ') --right;
        string word;
        deque<string> words;
        while (left <= right) {
            const char &c = s[left];
            if (!word.empty() && c == ' ') {
                words.emplace_back(word);
                word.clear(); 
            } else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        words.emplace_back(word);
        string result;
        while (!words.empty()) {
            result += words.back();
            words.pop_back();
            if (!words.empty()) {
                result += ' ';
            }
        }        
        return result;
    }
};