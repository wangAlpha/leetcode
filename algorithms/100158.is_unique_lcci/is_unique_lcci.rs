impl Solution {
    pub fn is_unique(astr: String) -> bool {
        let mut chars = [false; 26];
        for &s in astr.as_bytes().iter() {
            let c = s as usize - 97;
            if chars[c] {
                return false;
            } else {
                chars[c] = true;
            }
        }
        true
    }
}