class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        # Initialize two lists to hold even and odd numbers separately.
        res1 = []  # List for even numbers
        res2 = []  # List for odd numbers

        # Iterate through the input list 'nums'.
        for i in range(len(nums)):
            # Check if the current number is even (divisible by 2).
            if nums[i] % 2 == 0:
                # If even, add it to the 'res1' list.
                res1.append(nums[i])
            else:
                # If odd, add it to the 'res2' list.
                res2.append(nums[i])

        # Concatenate the 'res1' (even) and 'res2' (odd) lists to obtain the final sorted list.
        return res1 + res2
