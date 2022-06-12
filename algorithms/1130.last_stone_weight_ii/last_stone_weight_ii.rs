impl Solution {
    pub fn last_stone_weight_ii(stones: Vec<i32>) -> i32 {
        let sum:i32 = stones.iter().sum();
        let target = sum as usize/2;
        let mut dp = vec![0; target as usize + 1];
        
        stones.iter().for_each(|&stone| {
            for j in (stone as usize..=target).rev() {
                dp[j] = dp[j].max(dp[j - stone as usize] + stone as usize);
            }
        });
        sum - dp[target] as i32 * 2
    }
}