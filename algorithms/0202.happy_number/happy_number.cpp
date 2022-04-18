class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            const int num = n % 10;
            sum += num * num;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (true) {
            const int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (set.find(sum) != set.end()) {
                return false;
            }
            set.insert(sum);
            n = sum;
        }
        return true;
    }
};