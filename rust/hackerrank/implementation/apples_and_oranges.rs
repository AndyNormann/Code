use std::io;

fn main() {
    let mut line1 = String::new();
    let mut line2 = String::new();
    let mut line3 = String::new();
    let mut line4 = String::new();
    let mut line5 = String::new();

    io::stdin().read_line(&mut line1).unwrap();
    io::stdin().read_line(&mut line2).unwrap();
    io::stdin().read_line(&mut line3).unwrap();
    io::stdin().read_line(&mut line4).unwrap();
    io::stdin().read_line(&mut line5).unwrap();


    let nums: Vec<i32> = 
        format!("{} {} {} {} {}", line1, line2, line3, line4, line5)
        .split(' ')
        .map(|s| s.trim()
             .parse()
             .unwrap())
        .collect();


    let s = nums[0];
    let t = nums[1];
    //let a = nums[2];
    //let b = nums[3];
    let m = nums[4];
    let n = nums[5];
    let mut apple_distances = vec!();
    let mut orange_distances = vec!();

    for i in 6..6+m {
        apple_distances.push(nums[i as usize]);
    }

    for i in 6+m..6+m+n {
        orange_distances.push(nums[i as usize]);
    }

    let mut total_apple = 0;
    let mut total_orange = 0;

    println!("{:?}", apple_distances);
    println!("{:?}", orange_distances);

    for i in apple_distances {
        if i >= s && i <= t {
            total_apple += 1;
        }
    }
    
    for i in orange_distances {
        if i >= s && i <= t {
            total_orange += 1;
        }
    }

    println!("{}", total_apple);
    println!("{}", total_orange);
}
