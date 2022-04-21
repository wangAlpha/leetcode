class Solution {
public:
    string replaceSpace(string s) {
        const int empty_num = count(s.begin(), s.end(), ' ');
        const int old_size = s.size();
        s.resize(s.size() + empty_num * 2);
        int i = old_size - 1, j = s.size() - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 3; 
            } else {
                s[j] = s[i];
                --j;
            }  
            --i;
        }
        return s;
    }
};