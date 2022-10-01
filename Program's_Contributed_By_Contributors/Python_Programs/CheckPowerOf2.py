#Question : Given an integer n, return true if it is a power of two. Otherwise, return false.
#An integer n is a power of two, if there exists an integer x such that n == 2x.

def isPowerOfTwo(self, n: int) -> bool:
        if n<0:
            return False
        if str(bin(n)).count('1')==1:
            return True
        return False
