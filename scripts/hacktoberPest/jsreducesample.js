
 // Sum up the instances of each  element in array
 const transport = ['car', 'car', 'truck', 'truck', 'bike', 'walk', 'car', 'van', 'bike', 'walk', 'car', 'van', 'car', 'truck' ];
 const transportation = transport.reduce(function(obj, item){
   if(!obj[item]){
     obj[item] = 0;   
   }
   obj[item]++;
   return obj;
 }, {}); // start with emptry object or can init {car: 0, walk:0, ...}
 console.log(transportation);