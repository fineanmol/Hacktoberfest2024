# leetcode hard problem https://leetcode.com/problems/dungeon-game/

class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        d = collections.defaultdict(lambda : 100000000)
        d[(len(dungeon)-1,len(dungeon[0]))] = 1
        d[(len(dungeon),len(dungeon[0])-1)] = 1
        for i in range(len(dungeon)-1,-1,-1):
            for j in range(len(dungeon[0])-1,-1,-1):
                mx = dungeon[i][j] - min(d[(i+1,j)],d[(i,j+1)]) + 1
                if mx > 0:
                    d[(i,j)] = 1
                else:
                    d[(i,j)] = abs(mx) + 1
                    
        print(d[(0,0)])
        ans = d[(0,0)] if d[(0,0)] > 0 else abs(d[(0,0)]) + 1      
        return ans