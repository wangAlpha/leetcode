impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        // if nums.len() == 1{return nums[0];}
        let mut sum = vec![0; nums.len() + 1];
        for i in 0..nums.len() {
            sum[i + 1] = nums[i];
        }
        for i in 1..sum.len() {
            sum[i] = sum[i] + sum[i - 1];
            if sum[i] < 0 {
                sum[i] = 0;
            }
        }
        let result = *sum.iter().max().unwrap();
        if result == 0 {
            return *nums.iter().max().unwrap();
        } else {
            return result;
        }
    }   
}