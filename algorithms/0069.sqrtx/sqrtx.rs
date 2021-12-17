impl Solution {
    pub fn my_sqrt(n: i32) -> i32 {
        let n = n as i64;
        let mut x = n.clone();
        while x * x > n {
            x = (x + n / x) / 2;
        }
        x as i32
    }
}