impl Solution {
    pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
        let mut ways = Vec::<i32>::new();
        if expression.is_empty() {
            return ways;
        }
        for i in 0..expression.len() {
            let c = expression.as_bytes()[i] as char;
            if c == '+' || c == '-' || c == '*' {
                let left = Self::diff_ways_to_compute(expression[..i].to_string());
                let right = Self::diff_ways_to_compute(expression[i + 1..].to_string());
                for l in left.iter() {
                    for r in right.iter() {
                        match c {
                            '+' => ways.push(l + r),
                            '-' => ways.push(l - r),
                            '*' => ways.push(l * r),
                            _ => (),
                        };
                    }
                }
            }
        }
        if ways.is_empty() {
            ways.push(expression.parse().unwrap());
        }
        ways
    }
}