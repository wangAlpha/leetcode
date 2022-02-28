class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int pre = 0;
        flowerbed.push_back(0);
        for (int i = 0; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i] == 0 && pre == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n -= 1;
            }
            pre = flowerbed[i];
        }
        return n <= 0;
    }
};