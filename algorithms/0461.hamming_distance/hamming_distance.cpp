class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        while(x||y){
            bool result1 = x & 0x01;
            bool result2 = y & 0x01;
            if(result1 != result2){
                ++distance;
            }
            x >>= 1;
            y >>= 1;
        }
        return distance;        
    }
};