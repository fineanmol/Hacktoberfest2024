fn main() {
    // Print a simple message to the console
    println!("Hello, Rust!");

    // Declare a variable
    let x = 5;

    // Use pattern matching to conditionally print a message
    if x < 10 {
        println!("x is less than 10");
    } else {
        println!("x is greater than or equal to 10");
    }

    // Define a function
    fn greet(name: &str) {
        println!("Hello, {}!", name);
    }

    // Call the function
    greet("Alice");
}
