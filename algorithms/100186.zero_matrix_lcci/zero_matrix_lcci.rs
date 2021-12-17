use std::collections::HashSet;

impl Solution {
    fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut lines = HashSet::new();
        let mut rows = HashSet::new();
        for i in 0..matrix.len() {
            for j in 0..matrix[0].len() {
                if matrix[i][j] == 0 {
                    lines.insert(i);
                    rows.insert(j);
                }
            }
        }
        for i in 0..matrix.len() {
            for j in 0..matrix[0].len() {
                if lines.contains(&i) || rows.contains(&j) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}