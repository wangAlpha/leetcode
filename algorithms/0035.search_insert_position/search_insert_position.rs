impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let (mut lo, mut hi) = (0, nums.len());
        while lo < hi {
            let mi = (lo + hi) >> 1;
            if target < nums[mi] {
                hi = mi;
            } else {
               lo  = mi + 1;
            }
        }
        if 0 <= (lo - 1) as i32 && target == nums[lo - 1] {
            (lo - 1) as i32
        } else {
            lo as i32
        }
    }
}
