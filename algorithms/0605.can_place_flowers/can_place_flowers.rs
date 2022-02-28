impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut flowerbed = flowerbed.clone();
        flowerbed.insert(0, 0); flowerbed.push(0);

        for i in 1..flowerbed.len()-1 {
            if flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 {
                flowerbed[i] = -1;
            }
        }
        // println!("flowerbed = {:?}", flowerbed);
        flowerbed.iter().filter(|&&x| x == -1).count() >= n as usize
        // let mut count = 0;
        // for &n in flowerbed.iter() {
        //     if n == -1 {
        //         count += 1;
        //     }
        // }
        // count >= n
    }

}