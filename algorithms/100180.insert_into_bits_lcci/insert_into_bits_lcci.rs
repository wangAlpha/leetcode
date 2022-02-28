impl Solution {
    pub fn insert_bits(n: i32, m: i32, i: i32, j: i32) -> i32 {
        // let space_bits = (i32::MAX << (i+1)) | (0^(i32::MAX << j));
        let space_bits = !(((1 << (j - i + 1)) - 1) << i);
        (n & space_bits) | (m << i)
    }
}