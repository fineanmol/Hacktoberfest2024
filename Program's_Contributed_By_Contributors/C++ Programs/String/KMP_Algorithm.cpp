
/*                                     Knuth-Morris-Pratt (KMP) Algorithm

                               KMP Algorithm is One of Nice Pattern Matching Algorithm
*/
//Problem : Let's take source string or text have a length N and I want to search pattern of length M in source text

//Approach 1(Navie) : Using Nessted loop --> Time Complexity O(M * (N - M +1 ))

//Approch 2(KMP ALgorithm): Time Complexity O(M + N)

//Implementing KMP Algorithm:



#include<iostream>
#include<vector>
using namespace std;
//Step 1: Pre-Processing: Time Complexity O(m)
//Making 'lps' Array (Length of longest Prfix which is also the suffix).
//Here lps[i] represent the length of the longest suffix which is also a prefix
// O(M)
vector<int> GenerateLPS(string Pattern)  
{
        //Initialising Forward and Backword pointer
        int i=1;
        int j=0;
        int M=Pattern.length();//Pattern Length
        vector<int> lps(M,0); //lps array declaration

        while(i<M){
                if(Pattern[i]==Pattern[j]){ // charaters matched
                        lps[i]=j+1;//the current character at forward can also lead to the next backward character 
                        i=i+1;
                        j=j+1;
                }else{
                        if(j!=0) //if length of prefix isn't zero, we go to prev backward prefix of same character 
                                j=lps[j-1];
                        else{
                                lps[i]=0;
                                i++;
                        }

                }
        }
        return lps;

}
//OK Here goes String Matching !

//Step 2: String Matching

void Check_Pattern(string Pattern,string Text,int N,int M){
        int i=0;
        int j=0;
        vector<int> lps = GenerateLPS(Pattern); //geting lps Array
        while(i<N){
                if(Pattern[j]==Text[i]){
                        i++;
                        j++;
                }
                if(j==M)
                {
                        cout<<"Yay ! Pattern Found! At "<<i-j<<"\n";
                        j=lps[j-1];
                }
                if((j<M && i<N) && (Pattern[j]!=Text[i])){
                        j!=0 ? j = lps[j-1] : i+=1;
                }
        }
       
}
int main(){
        string Text,Pattern;
        int N,M;
        cout<<"Enter the length of Text: ";    cin>>N;
        cout<<"Enter Text :";                  cin>>Text;
        cout<<"Enter the length of Pattern: "; cin>>M;
        cout<<"Enter Pattern: ";               cin>>Pattern;
         
        Check_Pattern(Pattern,Text,N,M); //Time Complexity O(N + M)
        
        return 0;
}

/*
INPUT:

Enter the length of Text: 19
Enter Text :ABAAABAAAAABBAAAABA
Enter the length of Pattern: 4
Enter Pattern: AAAB


OUTPUT:
Yay ! Pattern Found! At 2
Yay ! Pattern Found! At 8
Yay ! Pattern Found! At 14

Explanation:

Time Complexity  O(N + M)


*/
