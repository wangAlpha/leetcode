#include <numeric>
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() < 2) {
            return ratings.size();
        }
        vector<int> number(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                number[i] =  number[i-1] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; --i) {
            if (ratings[i] < ratings[i-1]) {
                number[i-1] = max(number[i-1], number[i] + 1);
            }
        }
        return accumulate(number.begin(), number.end(), 0);
    }
};