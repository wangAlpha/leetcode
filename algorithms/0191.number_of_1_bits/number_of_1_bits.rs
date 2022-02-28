impl Solution {
    pub fn hammingWeight (n: u32) -> i32 {
        let mut bits = n;
        let mut count = 0;
        
        while bits > 0 {
            count += 1;
            bits &= (bits - 1);
        }
        count
    }
}