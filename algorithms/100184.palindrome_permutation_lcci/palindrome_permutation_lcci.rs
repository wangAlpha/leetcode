impl Solution {
    pub fn can_permute_palindrome(s: String) -> bool {
        let mut chars = [false; 256];
        for c in s.into_bytes() {
            chars[c as usize] = !chars[c as usize];
        }
        chars.iter().map(|&x| x as i32).sum::<i32>() <= 1
    }
}