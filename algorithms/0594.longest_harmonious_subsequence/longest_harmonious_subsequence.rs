use std::collections::HashMap;
impl Solution {
    
    fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut maximum = 0;

        let mut number_counter = HashMap::new();
        for n in nums.iter() {
            let mut counter = number_counter.entry(n).or_insert(0);
            *counter += 1;
        }

        for &n in nums.iter() {
            if number_counter.contains_key(&(n + 1)) {
                maximum = maximum.max(number_counter[&n] + number_counter[&(n + 1)]);
            }
        }
        maximum
    }
}