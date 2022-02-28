impl Solution {
    pub fn reverse(x: i32) -> i32 {
        if x / 10 >= i32::MAX || x / 10 <= i32::MIN {
            return 0;
        }
        let mut number = x.abs() as i64;
        let mut result = 0i64;
        
        while number > 0 {
            let n = number % 10;
            result = result * 10 + n;
            number /= 10;
        }
        if result > i32::MAX as i64 || result < i32::MIN as i64 { return 0;}
        result as i32 * if x < 0 { -1 } else { 1 }
    }
}