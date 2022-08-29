impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.is_empty() {
            return false;
        }
        let (mut x, mut y) = (0, matrix[0].len() as i32 - 1);
        while x < matrix.len() && y >= 0 {
            if matrix[x][y as usize] == target {
                return true;
            } else if matrix[x][y as usize] > target {
                y -= 1;
            } else {
                x += 1;
            }
        }
        false
    }
}
