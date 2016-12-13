use std::io;

fn main() {

    let (mut a, m) = match read_inputs() {
        Ok((a, m)) => (a, m),
        Err(e) => {
            println!("Error: {}", e); 
            return;
        },
    };

    for _ in 0..a.len() {
        rotate_array_left(&mut a);
    } 

    for i in m {
        println!("{}", a[i as usize]);
    }
}

fn read_inputs() -> Result<(Vec<i32>, Vec<i32>), String> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).map_err(|e| e.to_string())?;

    let line: Vec<&str> = line.split(' ').collect();

    let q = line[2].parse::<i32>().map_err(|e| e.to_string())?;

    let mut line = String::new();
    io::stdin().read_line(&mut line).map_err(|e| e.to_string())?;

    let mut a: Vec<i32> = vec!();

    for num in line.split(' ') {
        a.push(num.parse::<i32>().map_err(|e| e.to_string())?);
    }

    let mut line = String::new();
    io::stdin().read_line(&mut line).map_err(|e| e.to_string())?;

    let mut m = vec!();

    for _ in 0..q {
        let mut line = String::new();
        io::stdin().read_line(&mut line).map_err(|e| e.to_string())?;
        m.push(line.trim().parse::<i32>().map_err(|e| e.to_string())?);
    }

    Ok((a, m))
}


fn rotate_array_left(array: &mut Vec<i32>) -> &mut Vec<i32> {
    let length = array.len();
    if length < 2 {
        return array
    }
    let temp = array[length - 1];

    for i in (1..length).rev() {
        array[i] = array[i - 1];
    }

    array[0] = temp;
    
    array
}
