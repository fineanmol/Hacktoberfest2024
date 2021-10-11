var s = '';

for ( var a = 10; a > 0; a-- ) {
 for ( var b = 1; b <= a; b++ ) {
  s += ' ';
 }
 for ( var c = 10; c >= a; c-- ) {
  s += '*';
 }
 for ( var d = 10; d > a; d-- ) {
  s += '*';
 }
 s += '\n';
}
for ( i = 0; i <= 10; i++ ) {
 for ( j = 1; j <= i; j++ ) {
  s += ' ';
 }
 for ( k = 10; k >= i; k-- ) {
  s += '*';
 }
 for ( l = 10; l > i; l-- ) {
  s += '*';
 }
 s += '\n';
}

console.log(s);