impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        if s.len() <= 1 {
            return true;
        }
        let mut filter_string = String::new();
        for c in s.chars() {
            if c.is_alphabetic() {
                filter_string.push(c.to_ascii_lowercase());
            } else if c.is_ascii_digit() {
                filter_string.push(c);
            }
        }
        // if filter_string.len() <= 1 && s.len() > filter_string.len() {
        //     return false;
        // }
        let (mut lo, mut hi) = (0i32, filter_string.len() as i32 - 1);
        let filter_chars = filter_string.as_bytes();
        while lo < hi {
            if filter_chars[lo as usize] != filter_chars[hi as usize] {
                return false;
            }
            lo += 1;
            hi -= 1;
        }
        true
    }
}