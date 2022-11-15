#include <bits/stdc++.h>

class Solution
{
public:
    int romanToInt(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

    int romanToInt(string s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && romanToInt(s[i]) < romanToInt(s[i + 1]))
            {
                num -= romanToInt(s[i]);
            }
            else
            {
                num += romanToInt(s[i]);
            }
        }
        return num;
    }
};