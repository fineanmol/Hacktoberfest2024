//Pokemon

function DigitalPal(hungry, sleepy, bored, age){
    this.hungry = hungry;
    this.sleepy = sleepy;
    this.bored = bored;
    this.age = age;
    this.feed = function(){
      if(this.hungry){
        console.log('That was tasty!');
        this.sleepy = true;
      }
      else{
        console.log("No thanks!");
      }
    }
    this.sleep = function(){
      if(this.sleepy){
        console.log("ZZzzzzzzzzz");
        this.sleepy = false;
        age++;
        console.log("I am awake and one day older!");
      }
      else{
        console.log("No thanks, not sleepy!");
      }
    }
    this.play = function(){
      if(this.bored){
        console.log("Let's play!");
        this.bored = false;
        this.hungry = true;
      }
      else{
        console.log("Not now, maybe later!");
      }
    }
  }
  
  DigitalPal.doMore = function(){
    console.log('FUCK');
  }
  
  let dog = new DigitalPal(false, false, true, 0);
  console.log(dog);
  dog.outside = false;
  dog.bark = function(){console.log("Woof!")};
  dog.bark();