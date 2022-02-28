type Table<T> = Vec<Vec<T>>;
impl Solution {
    
    pub fn exist(board: Table<char>, word: String) -> bool {
        let mut visited = vec![vec![false; board[0].len()]; board.len()];
        let word = word.chars().collect::<Vec<char>>();
        for i in 0..board.len() {
            for j in 0..board[0].len() {
                if Self::backtracking(&board, &word, &mut visited, 0, i, j) {
                    return true;
                }
            }
        }
        false
    }

    fn backtracking(
        board: &Table<char>,
        word: &Vec<char>,
        visited: &mut Table<bool>,
        k: usize,
        i: usize,
        j: usize,
    ) -> bool {
        if i >= board.len() || j >= board[0].len() || visited[i][j] {
            return false;
        }
        if board[i][j] != word[k] {
            return false;
        }
        visited[i][j] = true;
        if k == word.len() - 1 {
            return true;
        }
        // println!("{:?} {} k:{}", (i, j), board[i][j], k);
        if (j != 0 && Self::backtracking(board, word, visited, k + 1, i, j - 1))
            || Self::backtracking(board, word, visited, k + 1, i + 1, j)
            || (i != 0 && Self::backtracking(board, word, visited, k + 1, i - 1, j))
            || Self::backtracking(board, word, visited, k + 1, i, j + 1)
        {
            return true;
        }
        visited[i][j] = false;
        false
    }

}