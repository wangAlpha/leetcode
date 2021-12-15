impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut cell = [0u16; 9];
        let mut column = [0u16; 9];
        let mut line = [0u16; 9];

        for (i, line_) in board.iter().enumerate() {
            for (j, &n) in line_.iter().enumerate() {
                if n.is_digit(10) {
                    let shift: u16 = 1 << n.to_digit(10).unwrap();
                    let k = (i / 3) * 3 + (j / 3); // 第几个cell
                    if column[j] & shift > 0 || line[i] & shift > 0 || cell[k] & shift > 0 {
                        return false;
                    }
                    column[j] |= shift;
                    line[i] |= shift;
                    cell[k] |= shift;
                }
            }
        }
        true
    }
}