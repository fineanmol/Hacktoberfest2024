// Link to Problem : https://www.hackerrank.com/challenges/the-quickest-way-up/problem


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */
 
struct Node{
    int x,dist;
};

int bfs(int src, map<int, int> m){
    vector<int> visited(100,0);
    visited[0]=1;
    queue<Node> q;
    q.push({0,0});
    Node temp;
    int x,d;
    int min_dist=-1;
    while(q.empty()==false){
        temp = q.front();
        q.pop();
        x = temp.x;
        // y = temp.y;
        d = temp.dist;
        
        if(x==99){
            min_dist = d;
            return min_dist;
        }
        
        for(int i=x+1;i<=(x+6) && i<100;i++){
            if(visited[i]==false){
                if(m.find(i)==m.end()){
                    q.push({i,d+1});
                }
                else{
                    q.push({m[i], d+1});
                }
                visited[i]=true;
            }
        }
    }
    return min_dist;
}

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    map<int,int > m;
    for(int i=0;i<ladders.size();i++)
        m[ladders[i][0]-1] = ladders[i][1]-1;
    for(int i=0;i<snakes.size();i++)
        m[snakes[i][0]-1] = snakes[i][1]-1;
        
    int ans=bfs(0, m);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
