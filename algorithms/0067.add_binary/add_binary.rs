impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut result = String::new();
        let (mut a, mut b) = if a.len() > b.len() {
            (a.as_bytes(), b.as_bytes())
        } else {
            (b.as_bytes(), a.as_bytes())
        };
        let mut last = 0;
        for i in 0..a.len() {
            let (i, j) = (a.len() - i - 1, b.len() - i - 1);
            let n = if j < b.len() {
                (a[i] as char).to_digit(10).unwrap() + (b[j] as char).to_digit(10).unwrap() + last
            } else {
                (a[i] as char).to_digit(10).unwrap() + last
            };
            let c = if n == 1 || n == 3 { '1' } else { '0' };
            last = if n > 1 { 1 } else { 0 };
            result.push(c);
        }
        if last == 1 {result.push('1');}
        result.chars().rev().collect::<String>()
    }
}