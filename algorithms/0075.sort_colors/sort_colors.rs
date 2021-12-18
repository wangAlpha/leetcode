use std::collections::HashMap;

impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut colors = HashMap::new();
        for &num in nums.iter() {
            *colors.entry(num).or_insert(0) += 1;
        }
        let mut index = 0;
        for n in 0..3 {
            let &count = colors.get(&n).unwrap_or(&0);
            for _ in 0..count {
                nums[index] = n;
                index += 1;
            }
        }
    }
}