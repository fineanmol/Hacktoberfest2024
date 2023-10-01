#include <stdio.h>

int main() {
	int t;
	scanf("%d",&t);
	int n,a,b,s;
	for (int i=0;i<t;i++){
	    scanf("%d",&n);
	    char goals[2*n];
	    scanf("%s",goals);
	    s = 0;
	    for (int j=0;j!='\0';j++){
            printf("%c",goals[i]);
	        if (goals[j]=='1'){
	            if (j%2==0){
	                a++;
	            }
	            else{
	                b++;
	            }
	        }
	        if ((a>b+1)||(b>a+1)){
	            break;
	        }
	        s++;
	    }
	    printf("%d\n",s);
	}
	return 0;
}
