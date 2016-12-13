fn main() {
    let mut numbers: Vec<i32> = (0..10).collect();

    for (i, num) in numbers.iter().enumerate() {
        println!("{} {}", i, num);
    }

}
