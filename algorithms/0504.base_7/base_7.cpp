class Solution {
public:
    string convertToBase7(int num) {
        string numbers;
        int n = num > 0 ? num : -num;
        while (n >= 7) {
            const int mod = n % 7;
            numbers.push_back(mod + '0');
            n = (n - mod) / 7; 
        }
        numbers.push_back(n + '0');
        reverse(numbers.begin(), numbers.end());
        
        return num < 0 ? '-' + numbers: numbers;
    }
};