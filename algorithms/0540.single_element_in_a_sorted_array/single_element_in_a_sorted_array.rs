impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let (mut lo, mut hi) = (0, nums.len() - 1);
        while lo < hi {
            let mut mi = (hi - lo) / 2 + lo;
            if mi % 2 == 1 {
                mi -= 1;
            }
            if nums[mi] == nums[mi + 1] {
                lo = mi + 2;
            } else {
                hi = mi;
            }
        }
        nums[lo]
    }
}