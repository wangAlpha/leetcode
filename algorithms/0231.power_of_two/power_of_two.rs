impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n & (n - 1) == 0 && n > 0
    }
}