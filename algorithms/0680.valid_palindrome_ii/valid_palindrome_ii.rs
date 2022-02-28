impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let chars = s.as_bytes();
        let (mut lo, mut hi) = (0usize, chars.len() - 1);
        while lo < hi {
            if chars[lo] != chars[hi] {
                return Solution::is_palindrome(chars, lo + 1, hi) || Solution::is_palindrome(chars, lo, hi - 1);
            } else {
                lo += 1;
                hi -= 1;
            }
        }
        true
    }
    fn is_palindrome(chars: &[u8], lo: usize, hi: usize) -> bool {
        let (mut lo, mut hi) = (lo, hi);
        while lo < hi {
            if chars[lo] != chars[hi] {
                return false;
            }
            lo += 1;
            hi -= 1;
        }
        true
    }
}


