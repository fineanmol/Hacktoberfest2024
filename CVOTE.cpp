#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

int main() 
{
	int n,m,i;
	cin>>n>>m;
	int maxchefvote=0;
	int maxcountryvote=0;
	string maxchefname,maxcountryname;
	map<string,int> chefvote;
	map<string,int> countryvote;
	map<string,string> countryname;
	map< string , int >::iterator itr;
	
	for(i=0;i<n;i++)
	{  
	    string chefname, chefcountry;
	    cin>>chefname>>chefcountry;
	    countryname[chefname]=chefcountry;
	}
	
	for(i=0;i<m;i++)
	{   
	    string chefname;
	    cin>>chefname;
	    chefvote[chefname]++;
	    countryvote[countryname[chefname]]++;
	}
	
	for(itr=chefvote.begin();itr!=chefvote.end();itr++)
	{
	    if(itr->second>maxchefvote)
	    {
	       maxchefvote=itr->second;
	       maxchefname=itr->first;
	    }
	}
	
	
	for(itr=countryvote.begin();itr!=countryvote.end();itr++)
	{
	    if(itr->second>maxcountryvote)
	    {
	       maxcountryvote=itr->second;
	       maxcountryname=itr->first;
	    }
	}
	cout<<maxcountryname<<endl;
	cout<<maxchefname<<endl;
	
	
	
	return 0;
}
