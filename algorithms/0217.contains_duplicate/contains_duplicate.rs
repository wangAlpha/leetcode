use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut numbers = HashSet::new();
        for &n in nums.iter() {
            if numbers.contains(&n) {
                return true;
            } else {
                numbers.insert(n);
            }
        }
        false
    }
}