use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut alpha_table = HashMap::new();
        for &b in s.as_bytes().iter() {
            let counter = alpha_table.entry(b).or_insert(0);
            *counter += 1;
        }
        let mut odd_number = 0;
        let mut sum = 0;
        for &count in alpha_table.values() {
            if count % 2 == 1 {
                odd_number += 1;
            }
            sum += count;
        }
        if odd_number >= 1 {
            sum = sum - (odd_number - 1);
        }
        sum
    }
}