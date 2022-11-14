class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        def dfs(row, col, grid):
            
            if row < 0 or col < 0 or row >= len(grid) or \
            col >= len(grid[0]) or grid[row][col] != '1':
                return
            
            #mark as visited
            grid[row][col] = 'visited'
            
            for dx, dy in [(-1,0),(1,0),(0,1),(0,-1)]:
                dfs(row + dx, col + dy, grid)
                
        ans = 0

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if grid[row][col] == '1':
                    dfs(row, col, grid)
                    ans += 1
        return ans
