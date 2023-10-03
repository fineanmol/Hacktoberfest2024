public class AllPatterns {
    public static void main(String[] args) {
        int n = 5;

        // Q-1

        // Right Half Pyramid
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= i; j++) {
        // System.out.print("*\t");
        // }
        // System.out.println();
        // }

        /// Q_2
        // inverted left half pyramid
        // for (int i = 1; i <= n; i++) {
        // for (int k = 1; k < i; k++)
        // System.out.print("\t");
        // for (int j = 1; j <= n - i + 1; j++) {
        // System.out.print("*\t");
        // }
        // System.out.println();
        // }

        // //// Q-3
        // for (int i = 1; i <= n; i++) {
        // for (int k = 1; k < i; k++)
        // System.out.print("\t");
        // for (int j = 1; j <= n - i + 1; j++) {
        // System.out.print("*\t");
        // }
        // System.out.println();
        // }

        // //// Q-4
        // for (int i = 1; i <= n; i++) {

        // for (int j = 1; j <= i; j++) {
        // System.out.print(i + "\t");
        // }
        // System.out.println();
        // }

        // //// Q-4
        // for (int i = 1; i <= n; i++) {

        // for (int j = 1; j <= i; j++) {
        // System.out.print(j + "\t");
        // }
        // System.out.println();
        // }

        //// Q-5
        // left half pyramid
        // for (int i = 1; i <= n; i++) {
        // for (int k = 1; k <= n - i; k++)
        // System.out.print("\t");

        // for (int j = 1; j <= i; j++) {
        // System.out.print("*\t");
        // }
        // System.out.println();
        // }

        /// Q-6
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n - i + 1; j++) {
        // System.out.print("*\t");
        // }
        // System.out.println();
        // }

        //// Q-7
        // int nst = 2 * n - 1;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j < i; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= nst; k++) {
        // System.out.print("*\t");
        // }
        // nst -= 2;
        // System.out.println();
        // }

        // Q-8
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // System.out.print("*\t");
        // }
        // System.out.println();
        // }

        // Q-9
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == j)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // Q-10
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i + j == n + 1)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // Q-11
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == j || i + j == n + 1)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // Q-12
        // int sp = n - 1;
        // int st = 1;
        // for (int i = 1; i <= 2 * n - 1; i++) {
        // for (int j = 1; j <= sp; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= st; k++) {
        // System.out.print("*\t");
        // }
        // if (i < n) {
        // sp--;
        // st++;
        // } else {
        // st--;
        // sp++;
        // }
        // System.out.println();

        // }

        // Q-13
        // int sp = n - 1;
        // int st = 1;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= sp; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= st; k++) {
        // System.out.print("*\t");
        // }
        // st += 2;
        // sp--;
        // System.out.println();

        // }

        // Q-14

        // int st = 1;
        // for (int i = 1; i <= 2 * n - 1; i++) {
        // for (int k = 1; k <= st; k++) {
        // System.out.print("*\t");
        // }
        // if (i < n) {
        // st++;
        // } else {
        // st--;

        // }
        // System.out.println();

        // }

        // Q-15

        // for (int i = 1; i <= n; i++) {

        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || i == n || j == 1 || j == n) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();

        // }

        // Q-16
        // int st = 1;
        // int sp = n - 2;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= st; j++) {
        // System.out.print("*\t");
        // }
        // for (int k = 1; k <= sp; k++) {
        // System.out.print("\t");
        // }
        // System.out.println();
        // }

        // q18
        // int st = 1;
        // int sp = n / 2;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= sp; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= st; k++) {
        // System.out.print("*\t");
        // }
        // if (i < n / 2 + 1) {
        // st += 2;
        // sp--;
        // } else {
        // st -= 2;
        // sp++;
        // }
        // System.out.println();
        // }

        // q19
        // int st = 1;
        // int sp = n / 2;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= sp; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= st; k++) {
        // if (k == 1 || k == st)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // if (i < n / 2 + 1) {
        // st += 2;
        // sp--;
        // } else {
        // st -= 2;
        // sp++;
        // }
        // System.out.println();
        // }

        /// q-20
        // int num = 1;
        // int sp = 1;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= 2 * n - 1; j++) {
        // if (j <= i)
        // System.out.print(j + "\t");
        // else if (sp < 2 * n - i) {
        // System.out.print("\t");
        // } else {
        // System.out.print(num);
        // }
        // }
        // num = i;
        // System.out.println();
        // }

        // Q-21
        // int sp = n / 2;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j < n; j++) {
        // if (i == 1) {
        // System.out.print("*\t");
        // } else if (j <= sp) {
        // System.out.print("\t");
        // }
        // }
        // System.out.print("*\t");
        // System.out.println();
        // }

        // Q-22
        // int sp = n - 2;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == j) {
        // System.out.print("*\t");
        // } else if (j == n || j == 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }

        // System.out.println();
        // }

        // q-23
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= i; j++) {
        // if (i == j || j == 1 || i == n) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // q-24
        // int sp = 0;
        // int st = n;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= sp; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= st; k++) {
        // if (k == i || k == n - i + 1)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // if (i < n / 2 + 1) {
        // sp++;
        // st -= 2;
        // } else {
        // sp--;
        // st += 2;
        // }
        // System.out.println();
        // }

        // q-25
        // int st = n;
        // int sp = 0;
        // for (int i = 1; i <= n; i++) {
        // for (int k = 1; k <= sp; k++) {
        // System.out.print("\t");
        // }
        // for (int j = 1; j <= st; j++) {
        // System.out.print("*\t");
        // }
        // if (i < n / 2 + 1) {
        // st -= 2;
        // sp++;
        // } else {
        // st += 2;
        // sp--;
        // }
        // System.out.println();
        // }

        // q-24
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <=n; j++) {
        // if (i + j == n + 1 || i==j || i==1 || i==n )
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // q-26;
        // int st=1;
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==j || i+j==n+1 || j==1 || j==n){
        // System.out.print("*\t");
        // }
        // else{
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // q-27
        // int st = 1;
        // n = 7;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == j || i + j == n + 1 || j == 1 || j == n) {
        // System.out.print("*\t");
        // } else if (j <= i && j <= n - i || j >= i && j >= n - i + 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // T
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || j == n / 2 + 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // U
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (j==1 || j == n || i==n) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // S
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || i == n || (i == n / 2 + 1)|| (j==1 && i<=n/2+1) || j==n &&
        // i>=n/2+1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // B
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==1 || i==n/2+1 || i==n || j==1 || j==n){
        // System.out.print("*");
        // }
        // else{
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // H
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(j==1 || j==n || i==n/2+1){
        // System.out.print("*\t");
        // }
        // else{
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // Z
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==1 || i==n || i+j==n+1){
        // System.out.print("*\t");
        // }
        // else{
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        // P
        // n=9;
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==1 || i==n/2+1 || j==1 || j==n && i<=n/2+1){
        // System.out.print("*");
        // }
        // else{
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // L
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==n || j==1){
        // System.out.print("*");
        // }
        // else{
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // K
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (j+i==n+1 && i<=n/2+1 || j==1 || i==j && i>n/2) {
        // System.out.print("*");

        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // J
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==1 || j==n/2+1 || i==n && j<=n/2+1){
        // System.out.print("*");
        // }
        // else{
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // I
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || i == n || j==n/2+1) {
        // System.out.print("*");
        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // F
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || i==n/2+1 && j<=n/2+1 || j==1) {
        // System.out.print("*");
        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // E
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(i==1 || j==1|| i==n/2+1 || i==n){
        // System.out.print("*");
        // }
        // else{
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // Y
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i==j&&i<=n/2 || i+j==n+1 && i<=n/2 || j==n/2+1 && i>=n/2+1) {
        // System.out.print("*");
        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // R
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (j==1 || i==1 || j==n && i<=n/2+1 || i==n/2+1 || i>=n/2+1 && i==j) {
        // System.out.print("* ");
        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // N
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(j==n|| i==j || j==1){
        // System.out.print("* ");
        // }
        // else{
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }
        // swastika
        // n = 5;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (j == 1 && i <= n / 2 + 1 || j >= n / 2 + 1 && i == 1 || j == n / 2 + 1 ||
        // i == n / 2 + 1
        // || i == n && j <= n / 2 + 1 || j == n && i >= n / 2 + 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // System.out.println();
        // }

        // pascal
        // for (int line = 1; line <= n; line++) {
        // for (int j = 0; j <= n - line; j++) {
        // System.out.print(" ");
        // }
        // int C = 1;
        // for (int i = 1; i <= line; i++) {
        // System.out.print(C + " ");
        // C = C * (line - i) / i;
        // }
        // System.out.println();
        // }

        // n=10;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == j || j + i == n + 1 || j == 1 || j == n)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }

        // }
        // System.out.println();
        // }

        // int sp = n / 2;
        // int st = 5;
        // for (int i = 1; i <= n; i++) {
        // for (int k = 1; k <= sp; k++) {
        // System.out.print("\t");
        // }
        // for (int j = 1; j <= n; j++) {
        // if (i == 1) {
        // System.out.print("*\t");
        // } else {

        // }
        // }
        // }

        // E
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || i == n / 2 + 1 || i == n || j==1) {
        // System.out.print("* ");
        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }
        // 01
        // int nt=1;
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){
        // if(nt==1){
        // System.out.print(nt+"\t");
        // nt=0;
        // }
        // else{
        // System.out.print(nt+"\t");
        // nt=1;
        // }
        // }
        // System.out.println();
        // }

        // int sp=n/2;
        // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++){

        // }
        // }
        // diamond
        // int st = 1;
        // int sp = n / 2;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= sp; j++) {
        // System.out.print("\t");
        // }
        // for (int k = 1; k <= st; k++) {
        // if (k == 1 || k == st)
        // System.out.print("*\t");
        // else {
        // System.out.print("\t");
        // }
        // }
        // if (i < n / 2 + 1) {
        // st += 2;
        // sp--;
        // } else {
        // st -= 2;
        // sp++;
        // }
        // System.out.println();
        // }

        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (j == 1 || j == n || i == n / 2 + 1 || i==j || i + j == n + 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }

        // System.out.println();
        // }
        // n=9;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (j == 1 || j == n || i == j || i + j == n + 1 || j<=i && j<=n-i+1 ) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }
        // int st = 1;
        // n = 5;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == j || i + j == n + 1 || j == 1 || j == n) {
        // System.out.print("*\t");
        // } else if (j <= i && j <= n - i || j >= i && j >= n - i + 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }
        // n = 10;
        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if ((i == j ) || j == 1 || j == n || i == n || i == 1 || i + j == n + 1) {
        // System.out.print("* ");
        // } else {
        // System.out.print(" ");
        // }
        // }
        // System.out.println();
        // }

        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i == 1 || j == 1 || j == n || i == n) {
        // System.out.print("# ");
        // } else {
        // System.out.print("* ");
        // }
        // }
        // System.out.println();
        // }

        // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= n; j++) {
        // if (i < n / 2 + 1 && i == j || i > n / 2 && i + j == n + 1) {
        // System.out.print("*\t");
        // } else {
        // System.out.print("\t");
        // }
        // }
        // System.out.println();
        // }

        int arr[] = { 1, 5, 6, 4, 7 };
        int maxx = 0;
        for (int i = 0; i < arr.length; i++) {
            if (maxx < arr[i])
                maxx = arr[i];
        }
        for (int i = maxx; i >= 1; i--) {
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] >= i) {
                    System.out.print("*\t");
                } else {
                    System.out.print("\t");
                }
            }
            System.out.println();
        }

    }
}
