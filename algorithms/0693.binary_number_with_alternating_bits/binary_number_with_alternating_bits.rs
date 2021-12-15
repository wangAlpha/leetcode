impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let r = n ^ (n >> 1);
        (r + 1) & r == 0
    }
}