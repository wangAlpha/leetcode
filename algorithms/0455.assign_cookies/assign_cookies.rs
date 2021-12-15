impl Solution {
    pub fn find_content_children(children: Vec<i32>, cookie: Vec<i32>) -> i32 {
        let mut children = children;
        let mut cookies = cookie;
        // let mut count = 0;
        children.sort();
        cookies.sort();

        let (mut child, mut cookie) = (0usize, 0usize);
        while child < children.len() && cookie < cookies.len() {
            if children[child] <= cookies[cookie] {
                child += 1;
            }
            cookie += 1
        }
        child as i32
    }
}