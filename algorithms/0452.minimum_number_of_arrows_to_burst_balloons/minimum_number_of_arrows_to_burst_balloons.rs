impl Solution {
    pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
        if points.is_empty() {
            return 0;
        }
        let mut points = points;
        points.sort_by(|a, b| a[1].cmp(&b[1]));
        let mut interval_counter = 0;
        let mut prev = points[0][1];
        for i in 1..points.len() {
            if prev >= points[i][0] {
                interval_counter += 1;
            } else {
                prev = points[i][1];
            }
        }
        points.len() as i32 - interval_counter
    }
}