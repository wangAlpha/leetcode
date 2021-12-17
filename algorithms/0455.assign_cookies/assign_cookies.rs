impl Solution {
    pub fn find_content_children(children: Vec<i32>, cookie: Vec<i32>) -> i32 {
        let mut children = children;
        let mut cookie = cookie;
        let mut count = 0;
        children.sort();
        cookie.sort();

        let (mut i, mut j) = (0usize, 0usize);
        while i < children.len() && j < cookie.len() {
            while j < cookie.len() && children[i] > cookie[j] {
                j += 1;
            }
            if j < cookie.len() {
                i += 1;
                j += 1;
                count += 1;
            }
        }
        count
    }
}