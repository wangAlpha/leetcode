impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut bits = x ^ y;
        let mut count = 0;

        while bits > 0 {
            let result = bits & 0x01;
            bits >>= 1;
            if result != 0 {
                count += 1;
            }
        }
        count
    }
}