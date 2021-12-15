pub fn is_palindrome(s: &[u8], mut lo: usize, mut hi: usize) -> bool {
    if lo > hi {
        return false;
    }
    while lo < hi {
        if s[lo] != s[hi] {
            return false;
        }
        lo += 1;
        hi -= 1;
    }
    true
}
impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let bytes = s.as_bytes();
        let (mut lo, mut hi) = (0, bytes.len() - 1);
        while lo < hi {
            if bytes[lo] != bytes[hi] {
                return is_palindrome(&bytes, lo + 1, hi) || is_palindrome(&bytes, lo, hi - 1);
            }
            lo += 1;
            hi -= 1;
        }
        true
    }
}
