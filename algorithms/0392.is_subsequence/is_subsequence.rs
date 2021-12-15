impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let (mut i, mut j) = (0usize, 0usize);
        let mut count = 0;
        while i <= j && i < s.len() && j < t.len() {
            if s[i] == t[j] {
                i += 1;
                j += 1;
                count += 1;
            } else {
                j += 1;
            }
        }
        count == s.len()
    }
}