impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let directions = [(0i32, 1i32), (1, 0), (0, -1), (-1, 0)];
        let mut index = 0usize;
        let mut cnt = 1;
        let (mut row, mut col) = (0i32, 0i32);
        let mut matrix = vec![vec![0; n as usize]; n as usize];

        let mut direction = &directions[index];
        let max = n * n;
        while cnt <= max {
            matrix[row as usize][col as usize] = cnt;
            let (next_row, next_col) = (row + direction.0, col + direction.1);
            cnt += 1;
            if next_row < 0 || next_row >= n || next_col < 0 || next_col >= n || matrix[next_row as usize][next_col as usize] != 0 {
                index += 1;
                direction = &directions[index % 4];
            }
            row += direction.0;
            col += direction.1;
        }
        matrix
    }
}