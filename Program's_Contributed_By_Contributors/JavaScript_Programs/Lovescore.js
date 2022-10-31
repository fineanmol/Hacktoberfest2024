//using random number generation

prompt("What is your name?");
prompt("What is their name?");

let lovescore = Math.random() * 100;
lovescore = Math.floor(lovescore) + 1;

alert(`Your lovescore is ${lovescore}% .`);

//using conditional statements

if (lovescore === 100) {
  alert(`Your lovescore is ${lovescore}% .  You both are made for each other.`);
} else if (lovescore >= 70) {
  alert(
    `Your lovescore is ${lovescore}% .  You both love each other like Kanye loves Kanye.`
  );
} else if (lovescore > 30) {
  alert(`Your lovescore is  ${lovescore} % . You love them more.`);
} else {
  return alert(`Your lovescore is ${lovescore}% .`);
}
