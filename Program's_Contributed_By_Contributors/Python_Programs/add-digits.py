# Runtime
# 19ms
# Beats 47.82%of users with Python
# Memory
# 13.16MB
# Beats 81.39%of users with Python

class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 0
        while(len(str(num)) >1):
            ls = str(num)
            total = 0
            for i in ls:
                total+=int(i)
            num = total
        return num