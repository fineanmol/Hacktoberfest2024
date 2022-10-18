function result(){
  var result=dice.roll()
}
dice = {
        sides: 6,
        roll: function () {
         var randomNumber = Math.floor(Math.random() * this.sides) + 1;
         return randomNumber; 
        }}
