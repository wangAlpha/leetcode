impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut alphabet = [0; 256];
        for ch in s.chars() {
            alphabet[ch as usize] += 1;
        }
        let mut result = -1;
        for (i, ch) in s.chars().enumerate() {
            if alphabet[ch as usize] == 1 {
                result = i as i32;
                break;
            }
        }
        result
    }
}