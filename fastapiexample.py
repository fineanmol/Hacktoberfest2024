from fastapi import FastAPI


app=FastAPI()

#creating local variables
counterparty=[{'aman':'2'},{'aniket':'5'},{'bob smith':'2'}]
instrumentalId=[{'anand':'5469'},{'akashay':'3545'},{'bob smith':'7452'}]
instrumentName=[{'anand':'guitar'},{'aniket':'piano'},{'bob smith':'guitar'}]
trader=[{'bob smith':'1'},{'aniket':'2'},{'akashay':'3'}]

@app.get("/trades/")
def trades(name):
    temp=[]
    t={}
    for i in counterparty:
        for j in i:
            if(j==name):
                t['counterparty']=i[j]
                temp.append(t)
                t={}
                break
        
    for i in instrumentalId:
        for j in i:
            if(j==name):
                t['instrumentalId']=i[j]
                temp.append(t)
                t={}
                break
        
    for i in instrumentName:
        for j in i:
            if(j==name):
                t['instrumentName']=i[j]
                temp.append(t)
                t={}
                break
    
    for i in trader:
        for j in i:
            if(j==name):
                t['trader']=i[j]
                temp.append(t)
                t={}
                break
    #returing all the values where bob given name exists e.g bob smith
    return temp

#getting single trade
tradesid=[{'1':'trade1'},{'2':'trade 2'},{'3':'trade 3'}]

@app.get("/singleTrade/")
def singletrade(tid):
    for i in tradesid:
        for j in i:
            if(j==tid):
                return i[j]


#listing all the trades
@app.get("/listingTrade/")
def lsitingtrade():
    temp=[]
    for i in tradesid:
        for j in i:
            temp.append(i[j])
    return temp
            
        
    
    
