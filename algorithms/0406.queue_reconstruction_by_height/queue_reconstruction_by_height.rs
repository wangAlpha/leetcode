impl Solution {
    pub fn reconstruct_queue(people: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        if people.is_empty() {
            return people;
        }
        let mut people = people;
        people.sort_by(|a, b| {
            if a[1].cmp(&b[1]) != std::cmp::Ordering::Equal {
                return a[1].cmp(&b[1]);
            }
            a[0].cmp(&b[0])
        });
        // println!("people = {:?}", people);
        for index in 1..people.len() {
            let cur_person = &people[index];
            let mut count = 0;
            for (i, person) in people.iter().enumerate() {
                if person[0] >= cur_person[0] {
                    count += 1;
                }
                if count > cur_person[1] && i < index {
                    let e = people.remove(index);
                    people.insert(i, e);
                    break;
                }
            }
        }
        people
    }
}