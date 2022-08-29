use std::collections::VecDeque;
impl Solution {

pub fn max_sliding_window(nums: Vec<i32>, window_size: i32) -> Vec<i32> {
    let window_size = window_size as usize;
    let mut maximums = vec![];
        let mut window = VecDeque::new();
    for (i, &n) in nums.iter().enumerate() {
        if !window.is_empty() && *window.front().unwrap() + window_size == i {
            window.pop_front();
        }
        while !window.is_empty() && nums[*window.back().unwrap()] < n {
            window.pop_back();
        }
        window.push_back(i);
        if i  >= window_size - 1 {
            maximums.push(nums[*window.front().unwrap()]);
        }
    }
    maximums
}
}
