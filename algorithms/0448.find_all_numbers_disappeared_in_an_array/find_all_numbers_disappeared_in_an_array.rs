impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut numbers = nums.clone();
        for &n in nums.iter() {
            numbers[n as usize - 1] = 0;
        }
        let mut result = vec![];
        for i in 0..nums.len() {
            if numbers[i] != 0 {
                result.push(i as i32 + 1);
            }
        }
        result
        // numbers.iter().map(|&x| x).filter(|x| *x != 0).collect()
    }
}