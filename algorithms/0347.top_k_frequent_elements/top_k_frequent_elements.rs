use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut dict = HashMap::new();
        for &n in nums.iter() {
            let mut counter = dict.entry(n).or_insert(0);
            *counter += 1;
        }
        let mut bucket: Vec<_> = dict.iter().collect();
        bucket.sort_by(|&a, &b| b.1.cmp(a.1));
        let mut result = vec![];
        for i in 0..k as usize {
            result.push(*bucket[i].0);
        }
        result
    }
}