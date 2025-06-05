class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        pairs = {')' : '(', '}' : '{', ']' : '['}
        inputs = ['(', '{', '[']
        stack = []
        for char in s:
            if char in inputs:
                stack.append(char)
            else:
                check = pairs[char]
    
                if len(stack) == 0 or check != stack[-1]:
                    return False
                else:
                    stack.pop()
        
        if len(stack) == 0:        
            return True
        return False
if __name__ == '__main__':
    s = Solution()
    print (s.isValid( "()"))
