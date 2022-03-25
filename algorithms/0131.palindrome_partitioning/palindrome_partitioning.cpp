class Solution {
public:
    void backtracking(string &s, int index) {
        if (index >= s.size()){
            result_.push_back(path_);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (is_palindrome(s, index, i)) {
                string ss = s.substr(index, i - index + 1);
                path_.push_back(ss);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path_.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result_;
    }
    bool is_palindrome(const string &s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) {
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<string>> result_;
    vector<string> path_; 
};