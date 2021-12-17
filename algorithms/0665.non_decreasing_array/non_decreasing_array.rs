impl Solution {
    pub fn check_possibility(nums: Vec<i32>) -> bool {
        let mut nums = nums;
        for i in 0..nums.len() - 1 {
            if nums[i] > nums[i + 1] {
                if i + 2 < nums.len() && nums[i] > nums[i + 2] {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
                break;
            }
        }
        // println!("nums = {:?}", nums);
        for i in 0..nums.len() - 1 {
            if nums[i] > nums[i + 1] {
                return false;
            }
        }
        true
    }
}