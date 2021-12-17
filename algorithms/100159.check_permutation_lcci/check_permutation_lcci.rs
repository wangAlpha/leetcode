impl Solution {
    pub fn check_permutation(s1: String, s2: String) -> bool {
        let mut chars = [0; 26];
        for &c in s1.as_bytes().iter() {
            chars[c as usize - 97] += 1;
        }
        for &c in s2.as_bytes().iter() {
            chars[c as usize - 97] -= 1;
        }
        for &c in chars.iter() {
            if c != 0 {
                return false;
            }
        }
        true
    }
}