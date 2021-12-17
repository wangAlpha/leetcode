impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let s = x.to_string();
        for (c, n) in s.as_bytes().iter().zip(s.as_bytes().iter().rev()) {
            if c != n {
                return false;
            }
        }
        return true;
    }
}