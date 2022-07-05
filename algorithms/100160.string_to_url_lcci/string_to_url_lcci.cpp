class Solution {
public:
    string replaceSpaces(string str, int length) {
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') {
                count += 2;
            }
        }
        int k = length + count - 1;
        for (int i = length - 1; i >= 0; --i) {
            if (str[i] == ' ') {
                str[k] = '0';
                str[k - 1] = '2';
                str[k - 2] = '%';
                k -= 3;
            } else {
                str[k] = str[i];
                k -= 1;
            }
        }
        str.resize(length + count);
        return str;
    }
};