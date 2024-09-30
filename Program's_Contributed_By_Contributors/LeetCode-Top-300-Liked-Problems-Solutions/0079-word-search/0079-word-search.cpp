class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int ind){
        // First check boundary cases
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || word[ind] != board[r][c])
            return false;

        if(ind == word.size() - 1) return true;
        
        char temp = board[r][c];
        board[r][c] = '.';

        bool found = false;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++){
            found |= dfs(board, word, r + dr[i], c + dc[i], ind + 1);
        }

        board[r][c] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(board[row][col] == word[0] && dfs(board, word, row, col, 0))
                    return true;
            }
        }
        return false;
    }
};