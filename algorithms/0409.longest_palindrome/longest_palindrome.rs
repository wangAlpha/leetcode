use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut sum = 0;
        let mut alpha_table = HashMap::new();
        for &b in s.as_bytes().iter() {
            let counter = alpha_table.entry(b).or_insert(0);
            *counter += 1;
            sum += 1;
        }
        let odd_number = alpha_table.values().fold(0, |s, &count| {
            if count % 2 == 1 {
                return s + 1;
            }
            s
        });
        if odd_number >= 1 {
            sum = sum - (odd_number - 1);
        }
        sum
    }
}