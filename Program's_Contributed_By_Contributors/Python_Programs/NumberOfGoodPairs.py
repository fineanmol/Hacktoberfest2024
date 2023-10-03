 def numIdenticalPairs(self, A):
        return sum(k * (k - 1) / 2 for k in collections.Counter(A).values())
