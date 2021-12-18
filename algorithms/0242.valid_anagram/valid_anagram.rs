impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        const base: usize = 'a' as usize;
        let mut alpha_table = [0; 26];
        for (&b1, &b2) in s.as_bytes().iter().zip(t.as_bytes().iter()) {
            alpha_table[b1 as usize - base] += 1;
            alpha_table[b2 as usize - base] -= 1;
        }
        alpha_table.iter().all(|&x| x == 0)
    }
}