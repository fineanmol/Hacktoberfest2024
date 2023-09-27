class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Handle negative numbers and numbers ending with 0 (except 0 itself)
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        
        reversed_x = 0
        original_x = x
        
        # Reverse the integer
        while x > 0:
            digit = x % 10
            reversed_x = reversed_x * 10 + digit
            x = x // 10
        
        # Check if the reversed integer is the same as the original
        return original_x == reversed_x
