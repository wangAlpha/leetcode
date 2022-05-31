impl Solution {
    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums.to_owned();
        let mut path = Vec::new();
        let mut visted = vec![false; nums.len()];
        let mut permutations = Vec::new();
        nums.sort();
        Self::backtracking(&nums, &mut path, &mut permutations, &mut visted);
        permutations
    }
    fn backtracking(nums: &Vec<i32>, path: &mut Vec<i32>, permutations: &mut Vec<Vec<i32>>, visted: &mut Vec<bool>) {
        if path.len() == nums.len() {
            permutations.push((*path).clone());
            return;
        }
        for i in 0..nums.len() {
            if i != 0 && nums[i] == nums[i - 1] && !visted[i - 1] {
                continue;
            }
            if !visted[i] {
                path.push(nums[i]);
                visted[i] = true;
                Self::backtracking(nums, path, permutations, visted);
                path.pop();
                visted[i] = false;
            }
        }
    }
}