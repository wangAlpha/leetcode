class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        size_t j = 0;
        for (const auto& house: houses) {
            while (j < heaters.size() - 1 && abs(heaters[j + 1] - house) <= abs(heaters[j] - house)) {
                ++j;
            }
            radius = max(radius, abs(heaters[j] - house));
        }
        return radius;
    }
};