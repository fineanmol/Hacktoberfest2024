#include<stdio.h>
#include<windows.h>
int main(){
	int h,m,s,d=0;
	//int de=1000;
	char d1;
	printf("\n enter 'D' for am or 'N' for pm\n");
	scanf("%c",&d1);
	if(d1=='D'||d1=='d')
	{
		d=1;
	}
	else if(d1=='N'||d1=='n')
	{
		d=2;
	}
	printf("\n enter the time\n");
	scanf("%d%d%d",&h,&m,&s);
	
	
	if(h>12 || m>60 || s>60 || h<1 )
	{
		printf("\n The input is wrong");
		exit(0);
	}
	
	while(1)
	{
		s++;
		if(s>59)
		{
			m++;
			s=0;
		}
		if(m>59)
		{
			h++;
			m=0;
		}
		if(h>12)
		{
			
			h=1;
		}
		if(h==12 && m==0 && s==0){
			d=d+1;
		}
		printf("\n clock :");
		printf("\n %02d:%02d:%02d",h,m,s);
		if(d%2==0)
		{
			
			printf(" pm");
		}
		else if(d%2!=0)
		{
			printf(" am");
	    }
		sleep(1);
		system("cls");
			
	}
 
 return(0);	
}
