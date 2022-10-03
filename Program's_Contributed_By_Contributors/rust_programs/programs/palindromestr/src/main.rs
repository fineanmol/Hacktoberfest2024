use std::io;

fn main() {
    let mut str=String::new();
    io::stdin().read_line(&mut str).unwrap();
    str=str.trim().to_string();
    let revstr=str.trim().chars().rev().collect::<String>();
    
    match str==revstr{
        true=>{
            println!("Palindrome String");
        }
        false=>{
            println!("No Match");
        }
    }
}
