impl Solution {
    

    fn rotate(nums: &mut Vec<i32>, k: i32) {
        if nums.len() <= 1 {
            return;
        }
        let mut k = k as usize;
        while k > nums.len() {
            k -= nums.len();
        }
        rotate_range(nums, 0, nums.len() - 1);
        rotate_range(nums, 0, k - 1);
        rotate_range(nums, k , nums.len() - 1)
    }
}
pub fn rotate_range(nums: &mut Vec<i32>, lo: usize, hi: usize) {
        let (mut lo, mut hi) = (lo as i32, hi as i32);
        while lo < hi {
            nums.swap(lo as usize, hi as usize);
            lo += 1;
            hi -= 1;
        }
    }