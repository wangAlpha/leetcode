func maxSubArray(nums []int) int {
    curr := 0
    max_sum := MinInt
    for _, n := range nums {
        curr += n
        max_sum = max(max_sum, curr)
        curr = max(curr, 0)
    }
    return max_sum
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

const MaxUint = ^uint(0) 
const MinUint = 0 
const MaxInt = int(MaxUint >> 1) 
const MinInt = -MaxInt - 1


    // int maxSubArray(const vector<int>& nums) {
    //     int curr = 0, max_sum = INT_MIN;
    //     for (const int &n: nums) {
    //         curr += n;
    //         max_sum = max(max_sum, curr);
    //         curr = max(curr, 0);
    //     }
    //     return max_sum;
    // }