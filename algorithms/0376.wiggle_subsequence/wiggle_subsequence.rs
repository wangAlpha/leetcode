impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        let mut last_diff = 0;
        let mut curr_diff = 0;
        let mut count = 1;
        for i in 1..nums.len() {
            curr_diff = nums[i] - nums[i - 1];
            if (curr_diff < 0 && last_diff >= 0) || (curr_diff > 0 && last_diff <= 0) {
                last_diff = curr_diff;
                count += 1;
            }
        }
        count
    }
}
