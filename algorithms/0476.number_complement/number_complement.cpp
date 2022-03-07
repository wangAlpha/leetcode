class Solution {
public:
    int findComplement(int num) {
        int s = -1;
        for (int i = 31; i >= 0; --i) {
            if (((num >> i) & 0x1) != 0) {
                s = i;
                break;
            }
        }
        int result = 0;
        for (int i = 0; i < s; ++i) {
            if (((num >> i) & 0x1) == 0) {
                result |= (0x1 << i);
            }
        }
        return result;
    }
};