impl Solution {
    pub fn swap_numbers(numbers: Vec<i32>) -> Vec<i32> {
        let mut numbers = numbers;
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers
    }
}