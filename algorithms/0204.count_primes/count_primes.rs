impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        let n = n as usize;
        let mut is_primes = vec![false; n];
        let mut count = 0;
        for i in 2..n {
            if !is_primes[i] {
                count += 1;
                let mut j = (i << 1);
                while j < n {
                    is_primes[j] = true;
                    j += i;
                }
            }
        }
        count
    }
}