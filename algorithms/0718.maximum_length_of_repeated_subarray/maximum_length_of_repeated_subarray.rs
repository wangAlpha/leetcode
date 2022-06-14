impl Solution {
    pub fn find_length(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let (m, n) = (nums1.len(), nums2.len());
        let mut dp = vec![0; n + 1];
        let mut last = vec![0; n + 1];
        let mut result = 0;
        for i in 1..=m {
            dp.swap_with_slice(&mut last);
            for j in 1..=n {
                if nums1[i - 1] == nums2[j - 1] {
                    dp[j] = last[j - 1] + 1;
                    result = result.max(dp[j]);
                } else {
                    dp[j] = 0;
                };
            }
        }
        result
    }
}