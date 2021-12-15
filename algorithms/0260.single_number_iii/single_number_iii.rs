use std::collections::HashMap;
impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut diff = nums.iter().fold(0i32, |r, n| r ^ n);
        diff &= -diff;
        let mut unique_nums = vec![0, 0];
        for &n in nums.iter() {
            if n & diff != 0 {
                unique_nums[0] ^= n;
            } else {
                unique_nums[1] ^= n;
            }
        }
        unique_nums
    }
}