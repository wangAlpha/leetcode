use std::collections::HashSet;
impl Solution {
    pub fn find_subsequences(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut subsequences = Vec::new();
        let mut sequence = Vec::new();
        Self::backtracking(&nums, 0, &mut sequence, &mut subsequences);
        subsequences
    }
    fn backtracking(nums: &Vec<i32>, index: usize, sequence: &mut Vec<i32>, subsequences: &mut Vec<Vec<i32>>) {
        if sequence.len() >= 2 {
            subsequences.push((*sequence).clone());
        }
        let mut bucket = HashSet::new();
        for i in index..nums.len() {
            if bucket.contains(&nums[i]) {
                continue;
            }
            if sequence.is_empty() || *sequence.last().unwrap() <= nums[i] {
                sequence.push(nums[i]);
                bucket.insert(nums[i]);
                Self::backtracking(nums, i + 1, sequence, subsequences);
                sequence.pop();
            }
        }
    }
}