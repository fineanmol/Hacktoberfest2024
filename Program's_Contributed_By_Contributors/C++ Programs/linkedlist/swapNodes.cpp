 vector<string> allStringNums{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> operations{"double", "triple"};

    string search;
    string ans = "";
    int op = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (i == s.length() - 1)
        {
            search.push_back(s.at(i));
        }
        if (isspace(s[i]) || i == s.length() - 1)
        {
            // cout << search << endl;
            auto it = find(allStringNums.begin(), allStringNums.end(), search);

            if (it != allStringNums.end())
            {
                if (op > 0)
                {

                    for (int j = 0; j < op; j++)
                    {
                        ans += to_string(it - allStringNums.begin());
                    }

                    op = 0;
                }
                else
                {
                    ans += to_string(it - allStringNums.begin());
                }
            }
            else
            {
                it = find(operations.begin(), operations.end(), search);
                if (it != operations.end())
                {
                    op = (it - operations.begin()) + 2;
                }
                // cout << it - operations.begin() << " " << op << endl;
            }

            search = "";
        }
        else
        {
            search.push_back(s.at(i));
        }
    }
    cout << ans << endl;

    return ans;
