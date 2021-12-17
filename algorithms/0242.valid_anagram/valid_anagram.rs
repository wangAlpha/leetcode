impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let mut alpha_table = [0; 256];
        for (&b1, &b2) in s.as_bytes().iter().zip(t.as_bytes().iter()) {
            alpha_table[b1 as usize] += 1;
            alpha_table[b2 as usize] -= 1;
        }
        alpha_table.iter().all(|&x| x == 0)
    }

}