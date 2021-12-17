impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut number = 0;
        for n in nums.iter() {
            number ^= n;
        }
        number
    }
}