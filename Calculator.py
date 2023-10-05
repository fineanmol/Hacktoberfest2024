import math

response=['Welcome to smart calculator','Thanks for enjoy with me ','Sorry ,this is beyond my ability']

def extract_from_text(text):
    l=[]
    for t in text.split(' '):
        try:
            l.append(int(t))
        except ValueError:
            pass
    return l

def lcm(a,b):
    L=a if a>b else b
    while L<=a*b:
        if L%a==0 and L%b==0:
            return L
        L+=1

def hcf(a,b):
    H=a if a<b else b
    while H>=1:
        if a%H==0 and b%H==0:
            return H
        H-=1

def add(a,b):
    return a+b

def sub(a,b):
    return a-b

def mul(a,b):
    return a*b

def div(a,b):
    return a/b

def mod(a,b):
    return a%b

def sqr(a):
    return math.pow(a,2)

def cube(a):
    return math.pow(a,3)

def sqrt(a):
    return math.sqrt(a)

def cubert(a):
    return math.pow(a,1/3)

def permu(n,r):
    if n < r:
        raise ValueError("n must be greater than or equal to r")
    else:
        return (math.factorial(n) // math.factorial(n - r))

def combin(n,r):
    if n < r:
        raise ValueError("n must be greater than or equal to r")
    else:
        return ((math.factorial(n)) // (n * math.factorial(n-r)))

def factorial(a):
    return math.factorial(a)

def end():
    print(response[1])
    input('press enter key to exit')
    exit()

def sorry():
    print(response[2])

bin_operations={'ADD':add,'PLUS':add,'SUM':add,'ADDITION':add,'SUB':sub,'SUBTRACT':sub, 'MINUS':sub,'DIFFERENCE':sub,'LCM':lcm,'HCF':hcf,'GCD':hcf,
                       'PRODUCT':mul, 'MULTIPLY':mul,'MULTIPLICATION':mul,'DIVISION':div,'MOD':mod,'REMAINDER':mod,'MODULAS':mod,
                          'PERMUTATION':permu,'COMBINATION':combin}

una_operations={'SQUARE':sqr,'CUBE':cube,'FACTORIAL':factorial}

root_operations={'SQUARE ROOT':sqrt,'CUBE ROOT':cubert}

operators={'+':add,'-':sub,'*':mul,'x':mul,'/':div,'%':mod}

commands={'EXIT':end,'END':end,'CLOSE':end}
		
print('--------------'+response[0]+'------------')

while True:
    print()
    text=input('enter your queries: ')
    split = text.split(' ')
    for i in range(len(split)-1):
        if split[i].upper() in bin_operations.keys():
            try:
                l = extract_from_text(text)
                r = bin_operations[split[i].upper()] (l[0],l[1])
                print(r)
            except:
                print('something went wrong plz enter again !!')
            finally:
                break
        elif split[i] in operators.keys():
            try:
                l = extract_from_text(text)
                r = operators[split[i]] (l[0],l[1])
                print(r)
            except:
                print('something went wrong,plz enter again !!')
            finally:
                break
            
        elif  split[i].upper() in una_operations.keys() and split[i+1].upper() not in una_operations.keys():
            try:
                l = extract_from_text(text)
                r = una_operations[split[i].upper()] (l[0])
                print(r)
            except:
                print('something went wrong plz enter again !!')
            finally:
                break
        elif (split[i]+' '+split[i+1]).upper() in root_operations.keys():
            try:
                l = extract_from_text(text)
                r = root_operations[(split[i]+' '+split[i+1]).upper()] (l[0])
                print(r)
            except:
                print('something went wrong plz try again !!')
            finally:
                break
            
        elif split[i].upper() in commands.keys():
            commands[split[i].upper()]()
            break

    else:
        sorry()
