class Solution {
public:
    vector<string> restoreIpAddresses(string &s) {
        if (s.size() > 12) {
            return {};
        }
        backtracking(s, 0, 0); 
        return result;
    }
    void backtracking(string &s, int index, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, index, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isValid(s, index, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum += 1;
                backtracking(s, i + 2, pointNum);
                pointNum -= 1;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
        }
    }
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; ++i) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
private:
    string path;
    vector<string> result;
};