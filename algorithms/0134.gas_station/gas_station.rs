impl Solution {
pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
    let mut sum = 0;
    let mut curr_sum = 0;
    let mut start = 0;
    for i in 0..gas.len() {
        let diff = gas[i] - cost[i];
        sum += diff;
        curr_sum += diff;
        if curr_sum < 0 {
            start = i as i32 + 1;
            curr_sum = 0;
        }
    }
    if sum < 0 {
        return -1;
    }
    start
}
}
