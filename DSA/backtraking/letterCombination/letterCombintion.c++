// 17. Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<string> res;
void solve(int idx,string &digit,string &temp,unordered_map<char,string> &mp){

  if(idx==digit.size()){
    res.push_back(temp);
    return;
  }
  if(digit.empty()){
    return;
  }
  char ch = digit[idx];
  string st = mp[ch];
  for(int i = 0;i<st.length();i++){
    temp.push_back(st[i]);
    solve(idx+1,digit,temp,mp);
    temp.pop_back();
  }
}
int main()
{
  string digit;
  cout << "Enter Digit : ";
  cin >> digit;
  res.clear();
  unordered_map<char, string> mp;
  mp['2'] = "abc";
  mp['3'] = "def";
  mp['4'] = "ghi";
  mp['5'] = "jkl";
  mp['6'] = "mno";
  mp['7'] = "pqrs";
  mp['8'] = "tuv";
  mp['9'] = "wxyz";
  string temp = "";
  solve(0,digit,temp,mp);
  for(auto ele:res){
    cout<<ele<<" ";
  }
  return 0;
}