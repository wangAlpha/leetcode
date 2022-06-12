impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n <= 2 {
            return n;
        }

        let mut f = [1, 2];
        for _ in 3..=n {
            let mut last = f[1];
            f[1] += f[0];
            f[0] = last;
        }
        f[1]
    }
}