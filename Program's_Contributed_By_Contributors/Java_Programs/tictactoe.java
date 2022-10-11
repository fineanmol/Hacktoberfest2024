import java.util.*;
class tictactoe {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("Enter value of n for \nNxN Tic-Tac-Toe Game");
int n = sc.nextInt();
char[][] board = new char[n][n];
for(int i = 0; i < n; i++) {
for(int j = 0; j < n; j++) {
board[i][j] = '*';
}
}
Scanner in = new Scanner(System.in);
System.out.print("Player 1 name: ");
String p1 = in.nextLine();
System.out.print("Player 2 name: ");
String p2 = in.nextLine();
boolean player1 = true;
boolean gameEnded = false;
while(!gameEnded) {
drawBoard(board);
if(player1) {
System.out.println(p1 + "'s Turn (x):");
} else {
System.out.println(p2 + "'s Turn (o):");
}
char c = '*';
if(player1) {
c = 'X';
} else {
c = 'O';
}
int row = 0;
int col = 0;
while(true) {
System.out.print("Enter a row number:(1-" + n + ")");
row = in.nextInt();
row=row-1;
System.out.print("Enter a column number:(1-" + n + ")");
col = in.nextInt();
col=col-1;
if(row < 0 || col < 0 || row >= n || col >= n) {
System.out.println(" Some error occured try again.");
} else if(board[row][col] != '*') {
System.out.println("Some error occured try again.");
} else {
break;
}
}
board[row][col] = c;
if(winner(board) == 'X') {
System.out.println("\n \t "+p1 + " has won!");
gameEnded = true;
} else if(winner(board) == 'O') {
System.out.println("\n \t "+p2 + " has won!");
gameEnded = true;
} else {
if(boardIsFull(board)) {
System.out.println("It's a tie!");
gameEnded = true;
} else {
player1 = !player1;
}
}
}
drawBoard(board);
System.out.printf("\n\n");
 }
public static void drawBoard(char[][] board) {
System.out.println("Board:");
for(int i = 0; i < board.length; i++) {
for(int j = 0; j < board[i].length; j++) {
System.out.print(board[i][j]);
}
System.out.println();
}
}
public static char winner(char[][] board) {
for(int i = 0; i < board.length; i++) {
boolean rowcheck = true;
char value = board[i][0];
if(value == '*') {
rowcheck = false;
} else {
for(int j = 1; j < board[i].length; j++) {
if(board[i][j] != value) {
rowcheck = false;
break;
}
}
}
if(rowcheck) {
return value;
}
}
for(int j = 0; j < board[0].length; j++) {
boolean colcheck = true;
char value = board[0][j];
if(value == '*') {
colcheck = false;
} else {
for(int i = 1; i < board.length; i++) {
if(board[i][j] != value) {
colcheck = false;
break;
}
}
}
if(colcheck) {
return value;
}
}
boolean diagleft = true;
char value1 = board[0][0];
if(value1 == '*') {
diagleft = false;
} else {
for(int i = 1; i < board.length; i++) {
if(board[i][i] != value1) {
diagleft = false;
break;
}
}
}
if(diagleft) {
return value1;
}
boolean diagright = true;
char value2 = board[0][board.length-1];
if(value2 == '*') {
diagright = false;
} else {
for(int i = 1; i < board.length; i++) {
if(board[i][board.length-1-i] != value2) {
diagright = false;
break;
}
}
}
if(diagright) {
return value2;
}
return ' ';
}
public static boolean boardIsFull(char[][] board) {
for(int i = 0; i < board.length; i++) {
for(int j = 0; j < board[i].length; j++) {
if(board[i][j] == '*') {
return false;
}
}
}
return true;
}}
