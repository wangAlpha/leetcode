impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        let mut i = 0;
        while i < intervals.len() && intervals[i][0] < new_interval[0] {
            i += 1;
        }
        intervals.insert(i, new_interval);

        let mut i = 0;
        let mut insert_intervals = vec![];
        while i < intervals.len() {
            let (first, mut last) = (intervals[i][0], intervals[i][1]);
            while i + 1 < intervals.len() && last + 1 > intervals[i + 1][0] {
                last = last.max(intervals[i + 1][1]);
                i += 1;
            }
            insert_intervals.push(vec![first, last]);
            i += 1;
        }
        insert_intervals
    }
}