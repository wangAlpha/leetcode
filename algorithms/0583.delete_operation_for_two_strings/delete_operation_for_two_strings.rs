impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let (word1, word2) = (word1.as_bytes(), word2.as_bytes()); 
        let (n, m) = (word1.len(), word2.len());
        let mut last = vec![0; m + 1];
        let mut dp = vec![0; m + 1];
        for i in 1..=n {
            dp.swap_with_slice(&mut last);
            for j in 1..=m {
                dp[j] = if word1[i - 1] == word2[j - 1] {
                    last[j - 1] + 1
                } else {
                    last[j].max(dp[j - 1])
                };
            }
        }
        (n + m) as i32 - 2 * dp[m]
    }
}