impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut last = 0;
        let mut sum = 0;
        for i in 1..prices.len() {
            let diff = prices[i] - prices[last];
            last = i;
            if diff > 0 {
                // last = i;
                sum += diff;
            }
        }
        sum
    }
}