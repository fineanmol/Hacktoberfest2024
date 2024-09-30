class Solution {
public:
    void fillColor(int r, int c, int n, int m, int srcColor, int newColor, vector<vector<int>>& img){
        if(r < 0 || r >= n || c < 0 || c >= m || img[r][c] != srcColor || img[r][c] == newColor)
            return;
        
        img[r][c] = newColor;
        
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, 1, -1, 0};

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            fillColor(nr, nc, n, m, srcColor, newColor, img);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> img = image;
        int n = img.size(), m = img[0].size();

        int srcColor = img[sr][sc];

        if(srcColor != newColor) {
            fillColor(sr, sc, n, m, srcColor, newColor, img);
        }

        return img; 
    }
};