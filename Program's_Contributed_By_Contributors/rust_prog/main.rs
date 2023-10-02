use std::{path::StripPrefixError, fmt::{Display, Debug}};

 

pub struct NewsArticle{
    pub author : String,
    pub headline:String,
    pub content:String,
}

 

 

impl Summary for NewsArticle{
    fn summarize_author(&self) -> String{
        format!("@{}", self.author)
    }
}

 

pub struct Tweet{
    pub username:String,
    pub content: String,
    pub reply:bool,
    pub retweet:bool,
}

 

impl Summary for Tweet{

 

    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }
     fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
}

 

//ONE METHOD IN ONE TRAIT

 

// pub trait  Summary{
//     // fn Summarize(&self) -> String; // we can creating any body
//     fn Summarize(&self)->String{ // this is default implementation
//         String::from("Read more...")
//     }

// }

 

 

//TWO METHODS IN ONE TRAIT
pub trait  Summary{

 

    fn summarize_author(&self) -> String;

 

    // fn Summarize(&self) -> String; // we can creating any body
     fn summarize(&self)->String{ // this is default implementation
        format!("(Read more from {}..)", self.summarize_author())
    }

}

 

//NOTIFY

 

// pub fn notify(item : &impl Summary){
//     println!("Breaking news!! {}", item.summarize());
// }

 

// TRAITS BOUNDS

 

 

// pub fn notify<T: Summary>(item :T){
//     println!("Breaking news!! {}", item.summarize());
// }

 

// Example 2 of Trait bounds

 

// pub fn notify(item1: &impl Summary, item2:&impl Summary){

 

// }

 

pub fn notify<T: Summary>(item1:&T, item2:&T){

 

}
//here some_function has generic type T that implements Display and Clone, U implements 
//Clone and Debug. But its very hard to read so we will use readable. we will use where claus for this
// fn some_function<T: Display + Clone, U: Clone+ Debug>(t: &T, u:&U){

 

// }

 

// fn some_function<T,U>(t:&T, u:&U) ->i32
//     where T: Display + Clone,
//         U: Clone+Debug
// {
//     //...
// }

 

 

//RETURN TYPES
//here we are returning any type that implements Summary traids
fn returns_summarizable()-> impl Summary{
    Tweet{
        username:String::from("Hi there I am tweeting"),
        content:String::from("of course, as you know I am tweeting"),
        reply:false,
        retweet:false,
    }
}

 

 

fn main(){

 

    //  let tweet = Tweet{
    //     username: String::from("@johndoe"),
    //     content: String::from("The sky is falling"),
    //     reply:false,
    //     retweet:false,
    //  };

 

    //  let article = NewsArticle{
    //     author:String::from("John"),
    //     headline:String::from("The sky is falling!"),
    //     content:String::from("The sky is not falling actually"),
    //  };
    //  println!("Tweet summary: {}", tweet.summarize());
    //  println!("Tweet summary: {}", article.summarize());

 

    //  notify(&article);

 

    println!("{}", returns_summarizable().summarize());

 

}