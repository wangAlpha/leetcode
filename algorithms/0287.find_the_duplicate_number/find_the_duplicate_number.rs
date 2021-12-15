impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        // let sum = (0..nums.len() as i32).sum::<i32>();
        // nums.iter().sum::<i32>() - sum
        let mut number = vec![0; nums.len()];
        for &n in nums.iter() {
            if number[n as usize - 1] == -1 {
                return n;
            } else {
                number[n as usize - 1] = -1
            }
        }
        1
    }
}