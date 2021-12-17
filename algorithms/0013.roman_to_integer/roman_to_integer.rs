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
        let mut numbers: Vec<i32> = s
            .as_bytes()
            .iter()
            .map(|&x| roman_dict[&(x as char)])
            .collect();
        let mut max = 0;
        let mut sum = 0;
        for &x in numbers.iter().rev() {
            if x < max {
                sum += -x;
            } else {
                sum += x;
                max = x;
            }
        }
        sum
    }
}
