class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string number = to_string(n);
        int flag = number.size();
        for (int i = number.size() - 1; i > 0; --i) {
            if (number[i] < number[i - 1]) {
                flag = i;
                --number[i - 1];
            }
        }
        for (int i = flag; i < number.size(); ++i) {
            number[i] = '9';    
        }
        return stoi(number);
    }
};