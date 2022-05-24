class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        // 田忌赛马
        const size_t len = nums1.size();
        vector<int> ans(len, 0);
        sort(nums1.begin(), nums1.end());
        size_t left = 0, right =  len - 1;
        const auto nums = sorted_array(nums2);
        for (const int &n: nums1) {
            auto [x, i] = nums[left];
            if (n > x) {
                ans[i] = n;
                ++left;
            } else {
                ans[get<1>(nums[right])] = n;
                --right;
            }
        }
        return move(ans);
    }
    vector<tuple<int, size_t>> sorted_array(const vector<int> &nums) {
        vector<tuple<int, size_t>> vec;
        for (size_t i = 0; i < nums.size(); ++i) {
            vec.emplace_back(make_tuple(nums[i], i));
        }
        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return get<0>(a) < get<0>(b);
        });
        return move(vec);
    }
};