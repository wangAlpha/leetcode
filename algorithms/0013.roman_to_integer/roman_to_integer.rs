use std::collections::HashMap;
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let roman_dict: HashMap<char, i32> = [
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]
        .iter()
        .cloned()
        .collect();
        let mut sum = 0;
        let mut max = 0;
        for &c in s.as_bytes().iter().rev() {
           let n = roman_dict[&(c as char)];
            if n < max {
                sum += -n;
            } else {
                sum += n;
                max = n;
            }
        }
        sum
    }
}
