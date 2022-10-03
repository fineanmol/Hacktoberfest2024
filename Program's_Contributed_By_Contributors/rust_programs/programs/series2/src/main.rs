fn main() {
    let mut sum=0.;
    for i in 1..20 {
        sum+=1./(i as f64);
    }
    println!("Sum is {}",sum);
}
