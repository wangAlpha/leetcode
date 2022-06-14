impl Solution {
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 {
            return nums.len() as i32;
        }
        let mut result = 0;
        let mut count = 1;
        let mut last = nums[0];
        for &n in nums[1..].iter() {
            if last < n {
                count += 1;
            } else {
                count = 1;
            }
            last = n;
            result = result.max(count);
        }
        result
    }
}