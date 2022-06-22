class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> ss(numRows);
        int flag = -1, i = 0;
        for (const char& c: s) {
            ss[i].push_back(c);
            if (i == 0 || i == numRows - 1) flag = -flag;
            i += flag;
        }
        string ans;
        for (string& str: ss) {
            ans.append(move(str));
        }
        return ans;
    }
};