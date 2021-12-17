impl Solution {
    pub fn erase_overlap_intervals(intervals: Vec<Vec<i32>>) -> i32 {
        if intervals.is_empty() {
            return 0;
        }
        let mut counter = 0;
        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[1].cmp(&b[1]));
        println!("{:?}", intervals);
        let mut prev = intervals[0][1];
        for i in 1..intervals.len() {
            if prev > intervals[i][0] {
                counter += 1;
            } else {
                prev = intervals[i][1];
            }
        }
        counter
    }
}