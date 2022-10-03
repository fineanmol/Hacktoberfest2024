use std::io;

fn main() {
    let students = 5;
    let mut reg: Vec<String> = vec![];
    let mut val = String::new();
    let mut bcb = 0;
    let mut bce = 0;

    for i in 0..students {
        println!("Enter registration number of {}: ", i + 1);
        io::stdin().read_line(&mut val).unwrap();
        reg.push(val.clone().replace('\n', ""));
        val.clear();
    }
    for i in &reg {
        if i.contains("BCB") {
            bcb += 1;
        } else if i.contains("BCE") {
            bce += 1;
        }
    }
    println!("BCB: {}", bcb);
    println!("BCE: {}", bce);
}
