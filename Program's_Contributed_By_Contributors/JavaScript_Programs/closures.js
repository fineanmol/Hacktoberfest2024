//This is how to create and use a closure in javascript

let getName = (name) => {
  return (getAge = (age) => {
    console.log(`your name is ${name} and your age is ${age}`);
  });
};

//calling the function

//using simple function call

getName("junaid shah")(12);
