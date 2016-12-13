fn main() {
    println!("{}", kaprekar(45));
}

fn kaprekar(num: i32) -> bool {
    let mut current_num = num * num;

    let mut nums = vec![];

    while current_num > 0 {
        nums.push(current_num % 10);
        current_num /= 10;
    }

    let nums_rev: Vec<i32> = nums.iter().cloned().rev().collect();

    for i in 0..nums.len() {
        let num1 = gather_numbers(&nums[0..i]);
        let num2 = gather_numbers(&nums_rev[0..i]);
        println!("{} {}", num1, num2);
    }

    let halla = gather_numbers(&nums);

    println!("{}", halla);
    false
}

fn gather_numbers(nums: &[i32]) -> i32 {
    let mut ret_val = 0;
    for i in (0..nums.len()).rev() {
        ret_val += i32::pow(10, (i as u32)) * nums[i];
    }
    ret_val
}
