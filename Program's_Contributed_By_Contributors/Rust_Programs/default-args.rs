// Source: https://www.sudipg.com.np/posts/default-argument-rust-using-macro/#-solution

macro_rules! print_this {
    ($a: expr) => {
        print_this_raw($a, 0, 0);
    };
    ($a: expr, $b: expr) => {
        print_this_raw($a, $b, 0);
    };
    ($a: expr, $b: expr, $c: expr) => {
        print_this_raw($a, $b, $c);
    };
}

fn print_this_raw(a: i32, b: i32, c: i32) {
    println!("a = {} >> b = {} >> c = {}", a, b, c);
}

fn main() {
    // a = 10, b = 0, c = 0
    print_this!(10);

    // a = 10, b = 20, c = 0
    print_this!(10, 20);

    // a = 10, b = 20, c = 30
    print_this!(10, 20, 30);
}
