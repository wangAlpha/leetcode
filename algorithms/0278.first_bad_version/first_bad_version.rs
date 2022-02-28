// The API isBadVersion is defined for you.
// isBadVersion(versions:i32)-> bool;
// to call it use self.isBadVersion(versions)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		if n == 1 {
            return n;
        }
        for i in (1..n).rev() {
            if !self.isBadVersion(i) {
                return i + 1;
            }
        }
        1
    }
}