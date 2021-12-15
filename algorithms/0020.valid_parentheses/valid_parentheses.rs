use std::collections::HashMap;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::with_capacity(s.len());
        let map: HashMap<char, char> = [(']', '['), (')', '('), ('}', '{')]
            .iter()
            .cloned()
            .collect();

        for ch in s.chars() {
            if ch == '(' || ch == '[' || ch == '{' {
                stack.push(ch);
            } else if map.contains_key(&ch) {
                if stack.is_empty() || map[&ch] != *stack.last().unwrap() {
                    return false;
                }
                stack.pop();
            } else {
                return false;
            }
        }
        stack.is_empty()
    }
}