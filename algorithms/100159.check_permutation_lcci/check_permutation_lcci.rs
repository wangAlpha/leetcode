impl Solution {
    pub fn check_permutation(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }
        let mut chars = [0i8; 26];
        for (&c1, &c2) in s1.as_bytes().iter().zip(s2.as_bytes()) {
            chars[c1 as usize - 97] += 1;
            chars[c2 as usize - 97] -= 1;
        }
        for &c in chars.iter() {
            if c != 0 {
                return false;
            }
        }
        true
    }
}