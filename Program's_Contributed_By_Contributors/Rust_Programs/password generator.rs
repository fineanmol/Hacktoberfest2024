use rand::Rng;

//--- Arrays for adjectives, nouns, and special symbols
const ADJECTIVES: [&str; 9] = ["Blue", "Red", "Shining", "Bothersom", "Wimsical", "Green", "Happy", "Angry", "Happy"];

const NOUNS: [&str; 7] = ["fish", "crab", "trilobite", "dog", "cat", "alien", "dinosaur"];

const SYMBOLS: [&str; 8] = ["!", "@", "#", "$", "%", "&", "*", "?"];

//--- main function
fn main() 
{
    //--- activate the rng
    let mut rng = rand::thread_rng();

    //--- randomly generate a number for selecting an adjective, a noun and a special symbol
    let adjective: usize = rng.gen_range(0..9);
    let noun: usize = rng.gen_range(0..7);
    let number: i32 = rng.gen_range(10..100);
    let symbol: usize = rng.gen_range(0..8);
    
    //--- concantonate them together and print the result
    println!("{}{}{}{}", ADJECTIVES[adjective], NOUNS[noun], number, SYMBOLS[symbol]);
}
