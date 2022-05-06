impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let amount = amount as usize;
        let coins = coins.iter().map(|&c|c as usize).collect::<Vec<usize>>();
        let mut dp = vec![0usize; amount + 1];
        dp[0] = 1;
        for i in 0..coins.len() {
            for j in coins[i]..=amount {
                dp[j] += dp[j - coins[i]];
            }
        }
        dp[amount] as i32
    }
}