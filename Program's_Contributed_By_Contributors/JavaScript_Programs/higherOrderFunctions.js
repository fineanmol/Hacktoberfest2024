const companies = [
  { name: "company one", category: "Finanace", start: 1981, end: 2003 },
  { name: "company two", category: "Retail", start: 1989, end: 2043 },
  { name: "company three", category: "Auto", start: 1451, end: 2053 },
  { name: "company four", category: "Crypto", start: 1681, end: 2603 },
  { name: "company five", category: "Factories", start: 1933, end: 2503 },
  { name: "company six", category: "Machines", start: 1931, end: 2203 },
  { name: "company seven", category: "Food", start: 1541, end: 2033 },
  { name: "company eight", category: "Clothes", start: 1581, end: 2093 },
  { name: "company nine", category: "Agritech", start: 1781, end: 2083 },
  { name: "company ten", category: "Cyber-security", start: 1581, end: 2883 },
  { name: "company eleven", category: "Clocks", start: 1986, end: 2803 },
  { name: "company twelve", category: "Oil", start: 1951, end: 2088 },
  { name: "company thirten", category: "Natural Gas", start: 1881, end: 2803 },
  { name: "company fourteen", category: "Retail", start: 1901, end: 2603 },
  { name: "company fifteen", category: "Food", start: 1281, end: 2303 },
];

const ages = [22, 23, 44, 45, 66, 71, 34, 54, 65, 34, 56, 29, 78, 95, 21];

//for loop

// for (let i = 0; i < companies.length; i++) {
//   console.log(companies[i]);
// }

//forEach loop

// companies.forEach((company) => {
//   console.log(company);
// });

// map function

// companies.map((company) => {
//   console.log(company);
// });

//filter method

//1. age

// const canDrink = ages.filter((age) => {
//   if (age >= 40) {
//     return true;
//   }
// });

// console.log(canDrink);

//2. companies

// const retailCompanies = companies.filter((company) => {
//   if (company.category === "Retail" || company.category === "Food") {
//     return true;
//   } else if (company.start >= 1500 && company.start <= 2093) {
//     return true;
//   }
// });

// console.log(retailCompanies);

//map

//create array  ofcompany names

// const companyName = companies.map((company) => {
//   return `${company.category} [${company.start} - ${company.end}]`;
// });
//  console.log(companyName);

let students = [
  { id: "001", name: "Anish", sports: "Cricket" },
  { id: "002", name: "Smriti", sports: "Basketball" },
  { id: "003", name: "Rahul", sports: "Cricket" },
  { id: "004", name: "Bakul", sports: "Basketball" },
  { id: "005", name: "Nikita", sports: "Hockey" },
];

let players = students
  .filter((student) => {
    return student.sports === "Cricket";
  })
  .map((student) => {
    return student.name;
  });

console.log("Cricekt player is " + players);
//The below code does the same thing except it iterates players function one more time and gives result in different lines.

// players.map((player) => {
//   console.log("Cricket player is " + player);
// });

//sort

const sortCompanies = companies.sort((c1, c2) => {
  if (c1.start < c2.start) {
    return 1;
  } else {
    return -1;
  }
});

console.log(sortCompanies);

//sort ages

const sortAges = ages.sort((a, b) => {
  return b - a; //in decending order
});
console.log(sortAges);

//reduce

const ageSum = ages.reduce((total, age) => {
  return total + age;
}, 0);

console.log(ageSum);
