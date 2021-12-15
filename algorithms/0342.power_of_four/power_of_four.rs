impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n > 0 && n & (n - 1) == 0 {
            let mut n = n;
            let mut zeros = 0;
            while n > 0 {
                if n & 0x01 != 1 {
                    zeros += 1;
                }
                n >>= 1;
            }
            return zeros % 2 == 0;
        }
        false
    }
}