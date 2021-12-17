impl Solution {
    pub fn compress_string(s: String) -> String {
        if s == "" {
            return s;
        }
        let mut chars = String::new();
        let (mut ch, mut count) = (s.as_bytes()[0] as char, 0);
        for c in s.chars() {
            if ch != c {
                chars.push(ch);
                chars.push_str(&count.to_string());
                ch = c;
                count = 1;
            } else {
                count += 1
            }
        }
        chars.push(ch);
        chars.push_str(&count.to_string());
        return if s.len() > chars.len() { chars } else { s };
    }
}