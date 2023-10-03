use std::io;
fn main() {
    println!("To end the program, type `exit` ");
    loop {
        println!("Type a positive integer");
        let mut int = String::new();
        io::stdin().read_line(&mut int).expect("");
        if int.trim() == "exit" {
            break;
        }
        let int: u32 = match int.trim().parse() {
            Ok(int) => int,
            Err(_) => continue,
        };
        println!("Fibonacci ({}) => {}", int, fib(int));
    }
}

fn fib(n: u32) -> u32 {
    if n <= 0 {
        return 0;
    } else if n == 1 {
        return 1;
    }
    fib(n - 1) + fib(n - 2)
}
