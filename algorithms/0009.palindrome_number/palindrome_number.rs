impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x == 0 {
            return true;
        }
        if x < 0 || x % 10 == 0 {
            return false;
        }

        let mut x = x;
        let mut revserse = 0;
        while x > revserse {
            revserse = revserse * 10 + x % 10;
            x /= 10;
        }
        x == revserse || x == revserse / 10
    }
}
