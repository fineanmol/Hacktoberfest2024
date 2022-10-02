#code by Hridhwesh

"""
Python program to convert a given valid roman number to it's integer value!

Input: 
      Enter the roman value to be converted: MCD

Output : 
      The integer of the roman is: 1400


"""

#code

def romanToInt(s):
        
        a=0
        characs= ['I','V','X','L','C','D','M']
        x=s
        if ( 1<= len(x) ) and ( len(x) <=15 ):
            for i in x:
                if i not in characs:
                    return 0
            for j in range(len(x)):
                if x[j]=='M':
                    if (j-1 != -1):
                        if x[j-1]=='C':
                            a+=800
                            continue
                    a = a +1000
                if x[j]=='D':
                    if (j-1 != -1):
                        if x[j-1]=='C':
                            a+=300
                            continue
                    a+=500
                if x[j]=='C':
                    if (j-1 != -1):
                        if x[j-1]=='X':
                            a+=80
                            continue
                    a+=100
                if x[j]=='L':
                    if (j-1 != -1):
                        if x[j-1]=='X':
                            a+=30
                            continue
                    a+=50
                if x[j]=='X':
                    if (j-1 != -1):
                        if x[j-1]=='I':
                            a+=8
                            continue
                    a+=10    
                if x[j]=='V':
                    if (j-1 != -1):
                        if x[j-1]=='I':
                            a+=3
                            continue
                    a+=5 
                if x[j]=='I':
                    a+=1
        return (a)

def main():
    s = input("Enter the roman value to be converted: ")  
    x= romanToInt(s)
    if (x==0):
        print("Please enter a valid Roman Number. Program Terminated!")
    else:
        print("The integer of the roman is: ", x)    

main()