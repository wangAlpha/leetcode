use std::{collections::HashSet, mem::swap};

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let chars = s.as_bytes();
        let mut s = s.clone();
        let (mut lo, mut hi) = (0, chars.len() - 1);
        let set: HashSet<u8> = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'].iter().map(|&c| c as u8).collect();
        while lo < hi {
            if !set.contains(&chars[lo]) {
                lo += 1;
            } else if  !set.contains(&chars[hi]) {
                hi -= 1;
            } else {
                unsafe {s.as_bytes_mut().swap(lo, hi);};
                lo += 1;
                hi -= 1;
            }
            
        }
        s
    }
}
