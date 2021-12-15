use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let mut longest_sequence = 0;
        let mut number_set: HashSet<&i32> = nums.iter().collect();
        for &number in nums.iter() {
            if number_set.contains(&number) {
                let mut counter = 1;
                let mut n = number - 1;
                while number_set.contains(&n) {
                    number_set.remove(&n);
                    n -= 1;
                    counter += 1;
                }
                let mut n = number + 1;
                while number_set.contains(&n) {
                    number_set.remove(&n);
                    n += 1;
                    counter += 1;
                }
                number_set.remove(&n);
                longest_sequence = longest_sequence.max(counter);
            }
            if number_set.is_empty() {
                break;
            }
        }
        longest_sequence
    }
}