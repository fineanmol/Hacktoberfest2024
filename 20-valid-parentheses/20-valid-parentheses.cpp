class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
      
      for(int i=0;i<s.size();i++)
      {
        if(s[i] == '{')
          sc.push(s[i]);
        else if(s[i] == '(')
          sc.push(s[i]);
        else if(s[i] == '[')
          sc.push(s[i]);
        
        if(sc.empty())
          return false;
        
        if(s[i] == '}')
        {
          if(sc.top() == '{')
          {
            sc.pop();
          }
          else
          {
            return false;
          }
        }
        else if(s[i] == ']')
        {
          if(sc.top() == '[')
          {
            sc.pop();
          }
          else
            return false;
        }
        else if(s[i] == ')')
        {
          if(sc.top() == '(')
            sc.pop();
          else
            return false;
        }
          
      }
      
      if(sc.empty())
        return true;
      else
        return false;
    }
};