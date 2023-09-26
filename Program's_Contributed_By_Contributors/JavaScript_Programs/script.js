'use strict';

// Data needed for a later exercise
const flights =
  '_Delayed_Departure;fao93766109;txl2133758440;11:25+_Arrival;bru0943384722;fao93766109;11:45+_Delayed_Arrival;hel7439299980;fao93766109;12:05+_Departure;fao93766109;lis2323639855;12:30';

// Data needed for first part of the section
const restaurant = {
  name: 'Classico Italiano',
  location: 'Via Angelo Tavanti 23, Firenze, Italy',
  categories: ['Italian', 'Pizzeria', 'Vegetarian', 'Organic'],
  starterMenu: ['Focaccia', 'Bruschetta', 'Garlic Bread', 'Caprese Salad'],
  mainMenu: ['Pizza', 'Pasta', 'Risotto'],


  openingHours: {
    thu: {
      open: 12,
      close: 22,
    },
    fri: {
      open: 11,
      close: 23,
    },
    sat: {
      open: 0, // Open 24 hours
      close: 24,
    },
  },

order: function(starterIndex, mainIndex){
  return [this.starterMenu[starterIndex], this.mainMenu[mainIndex]];
},
};

function orderDelivery({ starterIndex = 1, mainIndex = 0, time = '20:00', address }) 
{
  console.log(`Order received! ${this.starterMenu[starterIndex]} and ${this.mainMenu[mainIndex]} will be delivered to ${address} at ${time}`
  );
};

// Array Destructuring - Lecture 🧑‍💻
const arr = [2,3,4];
/* const a = arr [0]; //Normal way 
const b = arr [1];
const c = arr [2];  */

//destructruting easily 
const [x,y,z] = arr;
console.log(x,y,z);
console.log(arr);

/* const [first, second] = restaurant.categories;
console.log(first,second);  *///print the first and second variables in categories 
let[main, ,secondary] = restaurant.categories;  // priniting the first and third values at categories by ignoring the second 
console.log(main,secondary);


//Switching the main and secondary variables - normal way 
/* const temp = main;
main = secondary;
secondary = temp;
console.log(main,secondary);  */

//Easy way of Switching 
[main,secondary] = [secondary,main];
console.log(main,secondary);

// receive 2 return values from function
const[starter,mainCourse] = restaurant.order(2.0);
console.log(starter,mainCourse);


//nested Destructioning 
const nested = [2,4,[5,6]]; //array inside an array 
/* const [i,,j] = nested;
console.log(i,j); */

const [i, , [j,k]] = nested;
console.log(i,j,k);

//Default Values 
const [p =1 , q = 1, r =1] = [8,9];
console.log(p,q,r); //r becomes undefined without default values 


//Destructing Objeect - Lecture 🧑‍💻

const {name, openingHours ,categories} = restaurant;
console.log(name,openingHours,categories);

//changing the object names 
const {
  name: restaurantName,
  openingHours: hours,
  categories: tags,
} = restaurant;

console.log(restaurantName, hours, tags );

const{ menu = [], starterMenu: starters = []} = restaurant;
console.log(menu, starter);

//Nesting Variables 
let a = 111;
let b = 999;
const obj = {a: 23, b: 7, c: 14};
({a,b} = obj);
console.log(a,b);

//Nested Objects 
const {
  fri: {open: o, close: c},
} = openingHours;
console.log(o,c);



