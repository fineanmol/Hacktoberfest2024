class Solution:
    def searchMatrix(self, matrix, target) -> bool:
        for i in range(len(matrix)):
            if matrix[i][0]<=target:
                for j in range(len(matrix[i])):
                    if matrix[i][j]==target:
                        return True
        return False

# driver code
matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target= 3
sol=Solution()
print(sol.searchMatrix(matrix,target))
