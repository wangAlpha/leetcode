impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let mut c = c as i64;
        let (mut lo, mut hi) = (0i64, (c as f32).sqrt() as i64 + 1);
        while lo < hi {
            let r = lo * lo + hi * hi;
            if r < c {
                lo += 1;
            } else if r > c {
                hi -= 1;
            } else {
                return true;
            }
        }
        lo * lo + hi * hi == c
    }
}