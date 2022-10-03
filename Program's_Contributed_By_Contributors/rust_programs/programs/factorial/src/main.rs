use std::io;

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n = n.trim().parse::<i32>().unwrap();
    let mut f = 1;
    for i in 1..=n {
        f *= i;
    }
    println!("Factorial: {}", f);
}
