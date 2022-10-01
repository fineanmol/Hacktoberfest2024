#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
#define fo1(x, y) for (lli x = 0; x < y; x++)
#define fo2(x, y) for (lli x = 1; x <= y; x++)

int main()
{
    lli n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        lli a = 0, b = 0;
        if (s.length() == 1)
            cout << s << endl;
        else if (s[0] == s[s.length() - 1])
        {
            cout << s << endl;
        }
        else
        {
            cout << s.substr(0, s.length() - 1) << s[0] << endl;
        }
    }
}

// string s;
// cin >> s;
// lli len = s.length();
// lli i = 0, j = 1;
// len--;
// lli l1 = len;
// lli count = 0, count1 = 0;
// while (l1--)
// {
//     if (s[i] == 'a' && s[j] == 'b')
//     {
//         count++;
//     }
//     i++;
//     j++;
// }
// // cout<<count<<endl;
// i = 0;
// j = 1;
// while (len--)
// {
//     if (s[i] == 'b' && s[j] == 'a')
//     {
//         count1++;
//     }
//     i++;
//     j++;
// }
// // cout << count1 << endl;
// if (count == count1)
// {
//     cout << s << endl;
//     continue;
// }

// else
// {
//     if (count < count1)
//     {
//         lli a = count1 - count;
//         len = s.length();
//         len--;
//         i = 0;
//         j = 1;
//         while (len-- && a != 0)
//         {
//             if (s[i] == 'b' && s[j] == 'a')
//             {
//                 //cout << len << endl;
//                 if (len == 0)
//                 {
//                     s[j] = 'b';
//                     break;
//                 }
//                 else
//                 {
//                     s[i] = 'a';
//                     break;
//                 }
//             }
//             i++;
//             j++;
//         }
//     }
//     if (count > count1)
//     {
//         len = s.length();
//         len--;
//         i = 0;
//         j = 1;
//         lli a = count - count1;
//         // cout<<a<<endl;
//         while (len-- && a != 0)
//         {
//             if (s[i] == 'a' && s[j] == 'b')
//             {
//                 if (len == 0)
//                 {
//                     s[j] = 'a';
//                     break;
//                 }
//                 else
//                 {
//                     s[i] = 'b';
//                     break;
//                 }
//             }
//             i++;
//             j++;
//         }
//         // cout<<s<<endl;
//     }
// }
// cout << s << endl;