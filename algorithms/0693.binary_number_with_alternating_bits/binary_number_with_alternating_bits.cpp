class Solution {
public:
    bool hasAlternatingBits(int n) {
        int64_t num = n ^ (n >> 1) ;
        return (num & (num + 1)) == 0;
    }
};