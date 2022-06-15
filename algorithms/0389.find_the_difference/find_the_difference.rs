impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let mut ch = *t.last().unwrap();
        for i in 0..s.len() {
            ch ^= s[i] ^ t[i];
        }
        ch as char
    }
}