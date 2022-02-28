impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if haystack.len() < needle.len() {
            return -1;
        }
        if haystack.is_empty() && needle.is_empty() {
            return 0;
        }

        let (haystack, needle) = (haystack.as_bytes(), needle.as_bytes());
        let (mut lo, hi) = (0usize, haystack.len());
        while lo < hi {
            let mut i = 0usize;
            while lo < hi && i < needle.len() && haystack[lo] == needle[i] {
                lo += 1;
                i += 1;
            }
            // if lo >= 5 {
            //     println!(
            //         "lo : {}, i : {} haystack: {:?}, needle: {:?}",
            //         lo, i, haystack, needle
            //     )
            // }
            if i >= needle.len() {
                return (lo - i) as i32;
            }
            lo = lo - i + 1;
        }
        -1
    }
}