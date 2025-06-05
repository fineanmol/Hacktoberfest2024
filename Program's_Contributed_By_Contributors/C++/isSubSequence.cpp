/* 
Write a recursive function that, given two strings, returns whether the first string is a
subsequence of the second. For example, given hac and cathartic, you should return true,
but given bat and table, you should return false. 

-----TEST CASE 1-----
INPUT  : cathcalic hac
OUTPUT : 1

-----TEST CASE 2-----
INPUT  : table bat
OUTPUT : 0
*/


#include <iostream>
#include <string>
using namespace std;

bool isSubSequenceHelper(string s, string subSeq, string output, int index){
    if(index == s.size()){
        if(output == subSeq){
            return true;
        }
        return false;
    }

    bool ans1 = isSubSequenceHelper(s,subSeq,output,index+1);
    bool ans2 = isSubSequenceHelper(s,subSeq,output+=s[index],index+1);
    return ans1 || ans2;
}

bool isSubSequence(string s, string subSeq){
    
    int index = 0;
    string output = "";
    
    return isSubSequenceHelper(s, subSeq, output, index);
}

int main() {

    string s;
    string subSeq;

    cin>>s>>subSeq;

    cout<<isSubSequence(s,subSeq);

    return 0;
}
