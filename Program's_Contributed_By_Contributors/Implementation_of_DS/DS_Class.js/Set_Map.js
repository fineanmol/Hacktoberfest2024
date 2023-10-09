// JS Set Use Hash Table for efficient operation
// JS Set does not store value in sorted manner as C++, but it maintain uniqueness.
// C++ Set take O(logN) for most of the bellow opeartion.
// O(1) complexity in adding
console.log("Set Outputs:");
const mySet = new Set([1, 2, 3]);
mySet.add(4);
// O(1) complexity in deleting
mySet.delete(2);
// O(1) for searching a value
const exists = mySet.has(3); // true
// O(1) for returning size
const size = mySet.size;
// O(n) for iterating on set
mySet.forEach((value) => {
    console.log(value);
});


// JS Map also use Hash table
// JS Map also does not store key value pair in sorted manner as C++, it maintain insertion order.
// JS map take O(1) time for almost every bellow operation
console.log("\nMap Output:");
const myMap = new Map([["f",488]]);
// O(1) in insertion key, value
myMap.set("b", 188);
myMap.set("c", 288);
myMap.set("a", 88);
myMap.set("d", 388);
myMap.set("e", "Line");
//O(1) for deletion
myMap.delete("c");
// O(n) iteration on key, value of map
myMap.forEach((value, key) => {
    console.log(key, value);
});
//O(1) for get and has operation
console.log(myMap.get("a")); // "88"
console.log(myMap.has("c"))// false
  
  