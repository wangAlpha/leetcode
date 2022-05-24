use std::collections::HashMap;

impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![-1; nums1.len()];
        let mut stack = Vec::<i32>::new();
        let mut nums1_map = HashMap::new();
        for (i, &n) in nums1.iter().enumerate() {
            nums1_map.insert(n, i);
        }
        for &cur in nums2.iter() {
            while !stack.is_empty() && *(stack.last().unwrap()) < cur {
                let prev = nums1_map[stack.last().unwrap()];
                stack.pop();
                ans[prev] = cur;
            }
            if nums1_map.get(&cur).is_some() {
                stack.push(cur);
            }
        }
        ans
    }
}