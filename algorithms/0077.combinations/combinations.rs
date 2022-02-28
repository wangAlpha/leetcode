impl Solution {
    pub fn combine(n: i32, k: i32) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = Vec::new();
        let mut comb = vec![0; k as usize];
        let mut count = 0;
        Self::backtracking(&mut ans, &mut comb, &mut count, 1, n, k);
        ans
    }

    fn backtracking(
        ans: &mut Vec<Vec<i32>>,
        comb: &mut Vec<i32>,
        count: &mut i32,
        pos: i32,
        n: i32,
        k: i32,
    ) {
        if *count == k {
            ans.push(comb.to_vec());
            return;
        }
        for i in pos..=n {
            comb[(*count) as usize] = i;
            *count += 1;
            Self::backtracking(ans, comb, count, i + 1, n, k);
            *count -= 1;
        }
    }
}