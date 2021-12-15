impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut bits = 1i32 << 30;
        while bits & num == 0 {
            bits >>= 1;
        }
        bits <<= 1;
        bits - num - 1
    }
}