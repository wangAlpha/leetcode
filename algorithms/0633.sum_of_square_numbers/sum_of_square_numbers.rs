impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let (mut lo, mut hi) = (0, (c as f32).sqrt() as i32 + 1);
        
        while lo < hi {
            let sum = lo * lo + hi * hi;
            if sum == c {
                return true;
            } else if sum < c {
                lo += 1;
            } else {
                hi -= 1;
            }
        }
        c == lo * lo + hi * hi
    }
}