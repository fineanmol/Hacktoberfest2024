fn main() {
    let mut a=1;
    let mut b=1;
    let mut c=0;
    print!("{}, {}, ",a,b);
    for _i in 0..10{
        c=a+b;
        a=b;
        b=c;
        print!("{}, ",c);
    }
}
