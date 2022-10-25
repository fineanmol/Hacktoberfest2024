/*
Codefprces Problem 71/A

Problem Statement:  vSometimes some words like "localization" or "internationalization" are so long that writing them many times in one text is quite tiresome.

Let's consider a word too long, if its length is strictly more than 10 characters. All too long words should be replaced with a special abbreviation.

This abbreviation is made like this: we write down the first and the last letter of a word and between them we write the number of letters between the first and the last letters. That number is in decimal system and doesn't contain any leading zeroes.

Thus, "localization" will be spelt as "l10n", and "internationalization» will be spelt as "i18n".

You are suggested to automatize the process of changing the words with abbreviations. At that all too long words should be replaced by the abbreviation and the words that are not too long should not undergo any changes.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n>0){
         string s;
         cin>>s;
         int len=s.size();
         if(len<11){
             cout<<s<<endl;
         }
         else{
             cout<<s[0]<<len-2<<s[len-1]<<endl;
         }
         n--;
    }
    return 0;
}