impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums.to_owned();
        let len = nums.len();
        Self::buildMaxHeap(&mut nums);
        for i in 0..(k - 1) as usize {
            nums.swap(0, len - i - 1);
            Self::adjust_down(&mut nums, 0, len - i - 2);
        } 
        nums[0]
    }
    pub fn buildMaxHeap(nums: &mut Vec<i32>) {
        let len = nums.len();
        for i in (0..len/2).rev() {
            Self::adjust_down(nums, i, len - 1);
        }
    }
    pub fn adjust_down(nums: &mut Vec<i32>, root: usize, hi: usize) {
        let mut root = root.to_owned();
        let mut child = root * 2 + 1;
        while child <= hi {
            if child + 1 <= hi && nums[child + 1] > nums[child] {
                child += 1;
            }
            if nums[root] < nums[child] {
                nums.swap(root, child);
                root = child;
                child = child * 2 +1;
            } else {
                break;
            }
        }
    }
}