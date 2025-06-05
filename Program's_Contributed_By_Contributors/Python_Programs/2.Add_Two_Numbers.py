class Solution:
    def addTwoNumbers(self, l1 ,l2):
         list1,list2='',''
         for i in range(-1,-len(l1)-1,-1):
              list1= list1 + str(l1[i])
         for i in range(-1,-len(l2)-1,-1):
              list2= list2 + str(l2[i])
         result=str(int(list1)+int(list2))
         return_=[]
         for i in range(-1,-len(result)-1,-1):
              return_.append(int(result[i]))
         print(return_) 
              
        
        
        
a = Solution()
a.addTwoNumbers([2,4,3],[5,6,4])