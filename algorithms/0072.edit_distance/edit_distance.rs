impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        if word1.is_empty() || word2.is_empty() {
            return word1.len().max(word2.len()) as i32;
        }
        let (word1, word2) = (word1.as_bytes(), word2.as_bytes());
        let (n, m) = (word1.len(), word2.len());
        let mut dp = vec![0; m + 1]; 
        let mut last = vec![0; m + 1]; 
        for i in 1..=m {
            dp[i] = i as i32;
        }
        for i in 1..=n {
            dp.swap_with_slice(&mut last);
            dp[0] = i as i32;
            for j in 1..=m {
                dp[j] = if word1[i - 1] == word2[j - 1] {
                    last[j - 1]
                } else {
                    last[j].min(dp[j - 1]).min(last[j - 1]) + 1
                };
            }
        }
        dp[m]
    }
}