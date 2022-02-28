impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut merge_intervals = vec![];
        let mut i = 0;
        while i < intervals.len() {
            let (first, mut last) = (intervals[i][0], intervals[i][1]);

            while i + 1 < intervals.len() && intervals[i + 1][0] <= last  {
                last = last.max(intervals[i + 1][1]);
                i += 1;
            }
            merge_intervals.push(vec![first, last]);
            i += 1;
        }
        merge_intervals
    }
}