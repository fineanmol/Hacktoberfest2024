board=[0 for i in range(20)]
ctr=0
def printx(n):
 global ctr
 ctr=ctr+1
 print("Solution",ctr)
 for i in range(1,n+1,1):
 for j in range(1,n+1,1):
 if(board[i]==j):
 print("Q",end=' ')
 else:
 print("-",end=' ')
 print("\n")
 print("-----------------------------------")
def place(r,c):
 for i in range(1,r,1):
 if(board[i]==c):
 return 0
 else:
 if(abs(board[i]-c)==abs(i-r)):
 return 0
 return 1
def queen(r,n):
 for c in range(1,n+1,1):
 if(place(r,c)):
 board[r]=c
 if(r==n):
 printx(n)
 else:
 queen(r+1,n);
print("*********N Queens Problem Using Backtracking*********")
n=int(input("\nEnter number of Queens:"))
queen(1,n)
print("The number of solution for",n,"Queens problem",ctr)




