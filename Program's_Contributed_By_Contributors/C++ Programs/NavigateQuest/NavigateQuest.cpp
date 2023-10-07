//THIS IS NAVIGATE QUEST .IN THIS YOU CAN FOLLOW MAP AND EARN REWARDS .
//NOTE:YOU HAVE TO ENTER VALUES OF TWO DIRECTIONS TO EARN THE REWARDS.FOR EXAMPLE(AT w=3,n=1), YOU CAN EARN THE REWARD.


#include<iostream>
#include<unistd.h>
using namespace std;
void select(int w,int e,int s,int n,int rewards ){
	cout<<" w:"<<w<<',';
	cout<<" e:"<<e<<',';                  
	cout<<" s:"<<s<<',';                     
	cout<<" n:"<<n<<endl;
}
void zero(int& w,int& e, int& s,int& n){
	w=0;
	n=0;
	e=0;
	s=0;
}

int main()
{
	cout<<"\n\t---------------------------------------------------------------------------------------------------------\n";
	cout<<"\t\t                                        NAVIGATE QUEST                    \n";
	cout<<"\t---------------------------------------------------------------------------------------------------------\n\n";
	
	int w=0,e=0,s=0,n=0;
	char drtcn;
	int rewards=0;
	
	cout<<"Press w for west    \n";
	cout<<"Press e for east   \n";
	cout<<"Press n for north  \n";
	cout<<"Press s for south \n";
	cout<<"Press q to quit \n";
	
	cout<<"\t                N             \n";
	cout<<"\t                |            \n";
	cout<<"\t       *        3            \n";
	cout<<"\t                |             \n";
	cout<<"\t                2             \n";
	cout<<"\t                |             \n";
	cout<<"\t       *        1        *      \n";
	cout<<"\tW --4--3--2--1--|--1--2--3--4--E\n";
	cout<<"\t       *        1               \n";
	cout<<"\t                |               \n";
	cout<<"\t                2           *  \n";
	cout<<"\t                |               \n";
	cout<<"\t                3               \n";
	cout<<"\t                |               \n";
	cout<<"\t                S               \n";
	
	cout<<"\nEnter a direction :";
	cin>>drtcn;
	
	while (drtcn!='Q'){		
		
		if(drtcn=='w'){
		cout<<"Moved to west"<<endl;
		w++;	
	    }
	       
	    else if(drtcn=='e'){
		cout<<"Moved to east"<<endl;
		e++;
			    
	    }
	    else if(drtcn=='n'){
		cout<<"Moved to north"<<endl;
		n++;
	
	    }
	    else if(drtcn=='s'){
		cout<<"Moved to south"<<endl;
		s++;
	
	    }
		else{
		cout<<"Invalid intput"<<endl;

	    }
	    
	    if (e==3 && n==1){
	    	cout<<"\nYou earned the award";
	    	rewards++;
	    	cout<<"\nCurrent position ";
	    	select(w, e, s, n,rewards);
	    	cout<<"\nRewards earned "<<rewards<<endl;
	    	zero(w,e,s,n);
	    }
	    else if (e==4 && s==2){
	    	cout<<"\nYou earned the award";
	    	rewards++;
	    	cout<<"\nCurrent position ";
	    	select(w, e, s, n,rewards);	 
			cout<<"\nRewards earned "<<rewards<<endl;       
	        zero(w,e,s,n);
	    }
	    else if (w==3 && s==1){
	    	cout<<"\nYou earned the award";
	    	rewards++;
	    	cout<<"\nCurrent position ";
	    	select(w, e, s, n,rewards);
	    	cout<<"\nRewards earned "<<rewards<<endl;
	    	w=0;
	    	s=0;
	    }
	    else if (n==3 && w==3){
	    	cout<<"\nYou earned the award";
	    	rewards++;
	    	cout<<"\nCurrent position ";
	    	select(w, e, s, n,rewards);
			cout<<"\nRewards earned "<<rewards<<endl;	    
	    	zero(w,e,s,n);
	    }
	    else if (n==1 && w==3){
	    	cout<<"\nYou earned the award";
	    	rewards++;
	    	cout<<"\nCurrent position ";
	    	select( w, e, s, n,rewards);
			cout<<"\nRewards earned "<<rewards<<endl;	    
	    	zero(w,e,s,n);
	    }
	    else{
	    	cout<<"\nRewards earned "<<rewards<<endl;
		}
	    
	    cout<<"\nCurrent position ";
   	    cout<<" w:"<<w<<',';
	    cout<<" e:"<<e<<',';
	    cout<<" s:"<<s<<',';
	    cout<<" n:"<<n<<endl;  
	    
	    cout<<"\nEnter a direction:";
		cin>>drtcn;
	
	
	    if(drtcn=='q'){
		cout<<"\nQuit";
	   break;
	    }
   }
	return 0;
}
