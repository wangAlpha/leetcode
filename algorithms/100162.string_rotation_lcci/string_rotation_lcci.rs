impl Solution {
    pub fn is_fliped_string(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }
        let mut ss = s1.clone();
        ss.push_str(s1.as_str());
        ss.contains(&s2)
    }
}