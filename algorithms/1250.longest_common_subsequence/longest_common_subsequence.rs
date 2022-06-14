impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let (m, n) = (text1.len(), text2.len());
        let (text1, text2) = (text1.as_bytes(), text2.as_bytes());
        let (mut last, mut dp) = (vec![0; n + 1], vec![0; n + 1]);
        for i in 1..=m {
            dp.swap_with_slice(&mut last);
            for j in 1..=n {
                dp[j] = if text1[i - 1] == text2[j - 1] {
                    last[j - 1] + 1
                } else {
                    last[j].max(dp[j - 1])
                };
            }
        }
        dp[n]
    }
}