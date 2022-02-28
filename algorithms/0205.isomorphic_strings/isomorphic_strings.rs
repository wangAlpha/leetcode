use std::collections::HashMap;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut s_first_dict = [0; 256];
        let mut t_first_dict = [0; 256];
        let (s, t) = (s.as_bytes(), t.as_bytes());

        for i in 0..s.len() {
            if s_first_dict[s[i] as usize] != t_first_dict[t[i] as usize] {
                return false;
            }
            s_first_dict[s[i] as usize] = i + 1;
            t_first_dict[t[i] as usize] = i + 1;
        }

        true
    }
}