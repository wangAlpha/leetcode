impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut bits = n;
        let mut count = 0;
        
        while bits > 0 {
            if bits & 0x01 == 1 {
                count += 1;
            }
            bits >>= 1;
        }
        count
    }
}