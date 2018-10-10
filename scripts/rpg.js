function Character(name, profession, gender, age, strength, hp) {
  this.name = name;
  this.profession = profession;
  this.gender = gender;
  this.age = age;
  this.strength = strength;
  this.hp = hp;
  this.isAlive = function(){
    if(this.hp> 0){
      console.log("Alive");
    }
    else{
      console.log("Terminated");
    }
  };
  this.attack = function(victim){
    victim.hp = victim.hp - this.strength;
  };

  this.levelUp = function(){
    this.age++;
    this.strength +=5;
    this.hp +=25;
  }
}

function printStats(char){
  console.log(char);
}

let bigTony = new Character("Tony", "Waste Management", "Male", 55, 100, 100);
let uncleJunior = new Character("Junior", "Construction", "Male", 75, 50, 180);
let artie = new Character("Artie", "Restaurant", "Male", 40, 100, 100);
let chris = new Character("Christopher", "Film", "Male", 30, 120, 80);

bigTony.mount = "Suburban";
printStats(bigTony);

var arr = [bigTony, uncleJunior, artie, chris];

for(var i=0; i<arr.length; i++){
    console.log(arr[i]);
    var e = document.createElement('div');
    e.innerHTML = "<div class='character-box'><h1><i class='fas fa-walking'></i><span style='margin-left:10px;'>" + arr[i].name + "</span><h1>"
        + "<h2>" + arr[i].gender + ", " + arr[i].age + ", " + arr[i].profession + "</h2>"
        + "<p>Strength: " + arr[i].strength + "</p><p>Health: " + arr[i].hp + "</p><p>" + arr[i].gender + "</p></div>";
    document.getElementById('rpg').appendChild(e.firstChild);
}
