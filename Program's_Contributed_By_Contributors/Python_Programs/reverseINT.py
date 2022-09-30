Num = int(input())    
Rev = 0    
while(Num > 0):    
    Reminder = Num %10    
    Rev = (Rev *10) + Reminder    
    Num = Num //10 
if Num<0:
    Num = -(Num)
    while(Num > 0): 
        
        Reminder = Num %10    
        Rev = (Rev *10) + Reminder    
        Num = Num //10
    Rev = -(Rev)    
     
print(Rev)  