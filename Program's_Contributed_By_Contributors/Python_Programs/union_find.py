# Optimized union find program that implements union by rank 

class UnionFind: 
    def __init__(self, size):
        self.root = [i for i in range(size)]
        self.rank = [1] * size

    # Recurrsively update root 
    def find(self, n): 
        if self.root[n] != n: 
          self.root[n] = self.find(self.root[n])
        return self.root[n]
        
    def union(self, a, b): 
        fa = self.find(a)
        fb = self.find(b)

        if fa != fb: 
            if self.rank[fa] > self.rank[fb]: 
                self.root[fb] = fa
            elif self.rank[fa] < self.rank[fb]: 
                self.root[fa] = fb 
            else: 
                self.root[fa] = fb 
                self.rank[fb] += 1 

    def connected(self, x, y): 
        return self.find(x) == self.find(y)