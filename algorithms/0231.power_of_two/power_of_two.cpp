class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num_bits = 0;
        while (n > 0) {
            n = n & (n - 1);
            num_bits += 1;
        }
        return num_bits == 1;
    }
};