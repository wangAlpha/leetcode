class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        int ans = 0;
        for (int64_t i = 2; i < n; ++i) {
            ans += static_cast<int>(primes[i]);
            if (i * i < n) {
                for (int64_t j = i * i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return ans;
    }
};