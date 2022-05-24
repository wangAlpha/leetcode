impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let (mut lo, mut hi) = (0i32, nums.len() as i32);
        while lo < hi {
            let mi = (lo + (hi - lo) / 2) as usize;
            if nums[mi] == target {
                return mi as i32;
            } else if nums[mi] < target {
                lo = mi as i32 + 1;
            } else {
                hi = mi  as i32;
            }
        }
        -1
    }
}