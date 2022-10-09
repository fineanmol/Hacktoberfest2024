#include<bits/stdc++.h> 
using namespace std;
int main()
{
    //contest
   //  sync
    int t; 
    cin >> t;
    while(t--) {
      string s1, s2, s3;
      vector<int> cnt(300), num(10);
      cin >> s1;
      // cout << s1;
      sort(s1.begin(), s1.end());
      int sz1 = s1.length(), nine = 0, sz2;
      for(int i = 0; i < sz1; i++) {
        if(s1[i] == 'z'){
          num[0]++;
          cnt['z']++; cnt['e']++; cnt['r']++; cnt['o']++;
        }
        else if(s1[i] == 'w'){
          num[2]++;
          cnt['t']++; cnt['w']++; cnt['o']++;
        }
        else if(s1[i] == 'u'){
          num[4]++;
          cnt['f']++; cnt['o']++; cnt['u']++; cnt['r']++; 
        }
        else if(s1[i] == 'x'){
          num[6]++;
          cnt['s']++; cnt['i']++; cnt['x']++;
        }
        else if(s1[i] == 'g'){
          num[8]++;
          cnt['e']++; cnt['i']++; cnt['g']++; cnt['h']++; cnt['t']++;
        }          
      }

      for(int i = 0; i < sz1; i++) {
        if(cnt[s1[i]]){
          cnt[s1[i]]--;
        } else 
          s2 += s1[i];
      }

      sz2 = s2.size();
      for(int i = 0; i < sz2; i++) {
        if(s2[i] == 'o'){
          num[1]++;
          cnt['o']++; cnt['n']++; cnt['e']++;
        }
        else if(s2[i] == 't'){
          num[3]++;
          cnt['t']++; cnt['h']++; cnt['r']++; cnt['e'] += 2;
        }
        else if(s2[i] == 'f'){
          num[5]++;
          cnt['f']++; cnt['i']++; cnt['v']++; cnt['e']++;
        }
        else if(s2[i] == 's'){
          num[7]++;
          cnt['s']++; cnt['e']++; cnt['v']++; cnt['e']++; cnt['n']++;
        }
      }

      for(int i = 0; i < sz1; i++) {
        if(cnt[s2[i]]){
          cnt[s2[i]]--;
        } else if(s2[i] == 'i')
          num[9]++;
      }

      int ok = 0;
      for(int i = 1; i < 10; i++){
        if(num[i]){
          ok = i; 
          num[i]--;
          break;
        }
      }
      
      if(!ok)
        cout << 0;
      else {
        if(num[0]){
          cout << ok;
           for(int i = 0; i < 10; i++) {
             while(num[i]--)
               cout << i;
           }
        } else {
           num[ok]++;
           for(int i = 0; i < 10; i++) {
             while(num[i]--)
               cout << i;
           }
        }
      }
      cout << "\n";
    }

  return 0;
}
