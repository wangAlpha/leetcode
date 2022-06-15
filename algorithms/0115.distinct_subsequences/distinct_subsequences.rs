impl Solution {
    pub fn num_distinct(ss: String, substr: String) -> i32 {
        let (m, n) = (substr.len(), ss.len());
        let (ss, substr) = (ss.as_bytes(), substr.as_bytes());
        let (mut dp, mut last) = (vec![0u64; m + 1], vec![0u64; m + 1]);
        dp[0] = 1;
        last[0] = 1;
        for i in 1..=n {
            dp.swap_with_slice(&mut last);
            for j in 1..=m {
                dp[j] = if ss[i - 1] == substr[j - 1] {
                    last[j - 1] + last[j]
                } else {
                    last[j]
                };
            }
        }
        dp[m] as i32
    }
}