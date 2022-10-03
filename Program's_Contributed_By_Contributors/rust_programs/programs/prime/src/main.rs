use std::io;

macro_rules! read_line {
    ($($t: ty),*) => {{
        let mut line = String::new();
        let _ = io::stdin().read_line(&mut line);
        let mut iter = line.split_whitespace();
        ($(iter.next().unwrap().parse::<$t>().unwrap(),)*)
    }};
}

fn main() {
    let mut n = String::new();
    let x=read_line!();
    println!("{:?}",);
}
