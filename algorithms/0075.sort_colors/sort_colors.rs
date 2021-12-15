impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut bucket = [0; 3];
        for &n in nums.iter() {
            bucket[n as usize] += 1;
        }
        let mut i = 0usize;
        for (j, &number) in bucket.iter().enumerate() {
            for _ in 0..number {
                nums[i] = j as i32;
                i += 1;
            }
        }
    }
}