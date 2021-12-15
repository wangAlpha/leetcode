use std::mem::swap;

impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        let mut nums = nums.clone();
        Self::backtracking(&mut nums, 0, &mut ans);
        ans
    }

    pub fn backtracking(nums: &mut Vec<i32>, level: usize, ans: &mut Vec<Vec<i32>>) {
        if level == nums.len() - 1 {
            ans.push(nums.to_vec());
            return;
        }

        for i in level..nums.len() {
            nums.swap(i, level);
            Self::backtracking(nums, level + 1, ans);
            nums.swap(i, level);
        }
    }

}