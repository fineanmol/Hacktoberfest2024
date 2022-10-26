let x = 10;
let y = 5;
 
x += y; // artinya -> x = x + y;
x -= y; // artinya -> x = x - y;
x *= y; // artinya -> x = x * y;
x /= y; // artinya -> x = x / y;
x %= y; // artinya -> x = x % y;

console.log()

//Comparison Operator

//cotoh-contoh Comparison Operator
/**
 *  == | untuk membandingkan kedua dilai contoh nya misal a umurnya 10 b umur nay 10 kalu begitu true
 * != | membanding kan ketidak samaan
 * === | indentik
 * < >| lebih besar atau lebih kecil
 * >= | itu lah
 */

//persamaan identik
const aString = '10';
const aNumber = 10

console.log(aString == aNumber) // true, karena nilainya sama-sama 10
console.log(aString === aNumber) // false, karena walaupun nilainya sama, tetapi tipe datanya berbeda


//Logical Operator

/**
 * && | Operator dan (and). Logika akan menghasilkan nilai true apabila semua kondisi terpenuhi (bernilai true).
 * ||  |Operator atau (or). Logika akan menghasilkan nilai true apabila ada salah satu kondisi terpenuhi (bernilai true).
 * ! | Operator tidak (not). Digunakan untuk membalikkan suatu kondisi.

 */

 let a = 10;
 let b = 12;
 
 /* AND operator */
 console.log(a < 15 && b > 10); // (true && true) -> true
 console.log(a > 15 && b > 10); // (false && true) -> false
 
 /* OR operator */
 console.log(a < 15 || b > 10); // (true || true) -> true
 console.log(a > 15 || b > 10); // (false || true) -> true
 
 /* NOT operator */
 console.log(!(a < 15)); // !(true) -> false
 console.log(!(a < 15 && b > 10)); // !(true && true) -> !(true) -> false
 
