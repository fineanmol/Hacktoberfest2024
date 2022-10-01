// Code 34: Write a program that prints the numbers from 1 to 100. But for multiples of three, print 
// "Fizz" instead of the number, and for the multiples of five, print "Buzz". 
// For numbers which are multiples of both three and five, print "FizzBuzz" 



function fizzBuzz(){
    for(let i= 1; i <=100; i++){
        if(i%3 ==  0 && i%5 ==0 ){
            console.log('FizzBuzz' , i)
        }
        else if(i%3 ==0){
            console.log('Fizz', i)
        }
        else if(i%5 ==0){
            console.log('Buzz', i)
        }else{
            console.log
        }
        

    }
}

fizzBuzz()