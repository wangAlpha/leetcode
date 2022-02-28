impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut sum_list = vec![0; nums.len()];
        let mut prev = 0;
        for i in 0..nums.len() {
            sum_list[i] = prev + nums[i];
            prev = sum_list[i];
            if sum_list[i] < 0 {
                prev = 0;
            }
        }
        *sum_list.iter().max().unwrap_or(&0)
    }
}