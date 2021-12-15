impl Solution {
    pub fn maximum(a: i32, b: i32) -> i32 {
        let k = ((a as i64 - b as i64) >> 63) as i32;
        a * (k + 1) - b * k
    }
}