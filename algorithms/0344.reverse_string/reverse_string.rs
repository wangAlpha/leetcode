impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let ptr = s.as_mut_ptr();
        for (i, _) in s.iter().enumerate() {
            if i >= s.len() / 2 {
                break;
            }
            let j = s.len() - i - 1;
            unsafe {
                std::ptr::swap(ptr.offset(i as isize), ptr.offset(j as isize));
            }
        }
    }
}