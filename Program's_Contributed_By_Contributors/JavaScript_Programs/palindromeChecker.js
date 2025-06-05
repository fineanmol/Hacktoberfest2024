function palindromeChecker(n){
    let a = n.toString();
    let l=0;
    let h=a.length-1;
    while(h>l)
    {
        if(a[l++]!=a[h--]) return 'The number is not a plaindrome';
    }
    return 'The number is a plaindrome';
};