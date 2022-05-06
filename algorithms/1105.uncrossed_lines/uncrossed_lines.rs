impl Solution {
    pub fn max_uncrossed_lines(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let (n, m) = (nums1.len(), nums2.len());
        let mut dp = vec![0; m + 1];
        let mut last = vec![0; m + 1];
        for i in 1..=n {
            for j in 1..=m {
                if nums1[i - 1] == nums2[j - 1] {
                    dp[j] = last[j - 1] + 1;
                } else {
                    dp[j] = last[j].max(dp[j - 1]);
                }
            }
            dp.swap_with_slice(&mut last)
        }
        last[m].max(dp[m])
    }
}