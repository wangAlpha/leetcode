impl Solution {
    pub fn max_area(heights: Vec<i32>) -> i32 {
        let mut area = 0;
        let (mut lo, mut hi) = (0, heights.len() - 1);
        while lo < hi {
            let height = heights[lo].min(heights[hi]);
            let width = (hi - lo) as i32;
            area = area.max(height * width);
            if heights[lo] < heights[hi] {
                lo += 1;
            } else {
                hi -= 1;
            }
        }
        area
    }
}