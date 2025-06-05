# Tower(number , from , to , using)
def Tower(n,start,end,middle) :
    if(n==1):
        print("Move %i from %s to %s"%(n,start,end))

    else: 
        Tower(n-1,start,middle,end)
        print("Move %i from %s to %s"%(n,start,end))
        Tower(n-1,middle,end,start)

Tower(3,"A","C","B")
