impl Solution {
    pub fn next_greater_elements(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![-1; nums.len()];
        let mut greater_stack = Vec::<usize>::new();
        for i in 0..(nums.len() * 2) {
            while !greater_stack.is_empty()
                && nums[*greater_stack.last().unwrap()] < nums[i % nums.len()]
            {
                ans[greater_stack.pop().unwrap()] = nums[i % nums.len()];
            }
            greater_stack.push(i % nums.len());
        }

        ans
    }
}