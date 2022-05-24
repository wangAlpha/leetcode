impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut buy1, mut sell1) = (prices[0], 0);
        let (mut buy2, mut sell2) = (prices[0], 0);
        for i in 1..prices.len() {
            buy1 = buy1.min(prices[i]);
            sell1 = sell1.max(prices[i] - buy1);
            buy2 = buy2.min(prices[i] - sell1);
            sell2 = sell2.max(prices[i] - buy2);
        }
        sell2
    }
}