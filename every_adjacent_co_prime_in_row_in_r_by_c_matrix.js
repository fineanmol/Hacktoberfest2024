var readline = require('readline');
var reader = readline.createInterface({
  input: process.stdin,
  terminal: true
});

var lines = [];

reader.on('line', function (line) {
    lines.push(line);
});

reader.on('close', main);

function main(){
    var temp = lines[0].split(" "),i,j,t,u,ans;
    const r=Number(temp[0]),c=Number(temp[1]);
    const mat = [];
    for(i=1;i<=r;i++){
        mat.push(lines[i].split(" ").map(Number)); 
    }
    for(i=0;i<r;i++){
        ans=[]; 
        for(j=0;j<c;j++){
            if(j===c-1){
                t=gcd(mat[i][j-1],mat[i][j]); 
                if(t===1){
                    ans.push(mat[i][j]); 
                }
            }
            else if(j===0){
                t=gcd(mat[i][j],mat[i][j+1]);
                if(t===1){
                    ans.push(mat[i][j]); 
                }
            }
            else{
                t=gcd(mat[i][j],mat[i][j-1]);
                u=gcd(mat[i][j],mat[i][j+1]);
                if(t===1 || u===1){
                   ans.push(mat[i][j]); 
                }
            }
        }
        if(ans.length===0){
            console.log(-1);
        }
        else{
            console.log(...ans); 
        }
    }
}
function gcd(a,b){
    if(b===0)
       return a;
    return gcd(b,a%b); 
}
