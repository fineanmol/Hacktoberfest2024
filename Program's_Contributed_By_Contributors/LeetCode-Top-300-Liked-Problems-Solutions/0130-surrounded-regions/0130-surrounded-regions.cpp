class Solution {
private:
    void dfs(int r, int c, int n, int m, vector<vector<char>>& board){
        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O')
            return ;
        
        board[r][c] = '*';
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, 1, -1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            dfs(nr, nc, n, m, board);
        }

    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        // The idea here is if 'O' is gonna be in boundary, then it's not surrounded. So, we will mark all the O's that are in boundary or can be traversed by an O from the boundary

        // Capture the unsurrounded regions (O -> *)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                    dfs(i, j, n, m, board);
            }
        }

        // Capture the surrounded regions (O -> X)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        // Capture the surrounded regions (O -> X)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        // Un capture the unsurrounded regions (T -> O)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};