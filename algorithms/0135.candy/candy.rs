use std::cmp::max;

impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut candies = vec![1i32; ratings.len()];
        for i in 1..ratings.len() {
            if ratings[i-1] < ratings[i] {
                candies[i] = max(candies[i-1] + 1, candies[i]);
            }
        }
        
        for i in (0..ratings.len()-1).rev() {
            if ratings[i] > ratings[i+1] {
                candies[i] = max(candies[i+1] + 1, candies[i]);
            }
        }
        candies.iter().fold(0, |x, n| x+n)
    }
}