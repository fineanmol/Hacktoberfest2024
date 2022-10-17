#include<bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence) {
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<sentence.size();i++)
        {
            arr[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)
                return false;
        }
        return true;
    }

     int main(int argc, const char** argv) {

        string s;
        cin>>s;

        if(checkIfPangram(s))
            cout<<s<<" "<<"Is Pangram!";
        else
        {
            cout<<s<<" "<<"Is Not a Pangram!"
        }
        return 0;
    }

