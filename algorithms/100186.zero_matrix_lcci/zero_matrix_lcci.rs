use std::collections::HashSet;

impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let mut lines = HashSet::new();
        let mut rows = HashSet::new();
        for (i, line) in matrix.iter().enumerate() {
            for (j, &x) in line.iter().enumerate() {
                if matrix[i][j] == 0 {
                    lines.insert(i);
                    rows.insert(j);
                }
            }
        }
        for &i in lines.iter() {
            for j in 0..matrix[0].len() {
                matrix[i][j] = 0;
            }
        }
        for &j in rows.iter() {
            for i in 0..matrix.len() {
                matrix[i][j] = 0;
            }
        }
    }
}