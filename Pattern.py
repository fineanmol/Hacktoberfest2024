word="HACK"
a=0
x=""
size=4
m=2*size-2
for i in range(0,size):
    for j in range(0,m):
        print(end=" ")
    m=m-1
    for j in range(0,i+1):
        q=word[a]
        print(q, end=" ")
        a+=1
    a=0
    print(" ")
print()
print()
w="OCTOBER"
s=7
o=2*s-3
for i in range(0,s):
    for j in range(0,o):
        print(end=" ")
    o-=1
    for j in range(0,i+1):
        q=w[a]
        print(q, end=" ")
        a+=1
    a=0
    print(" ")
print()
print()
word="FEST"
s=7
o=2*s-3
size=4
m=2*size-2
for i in range(0,size):
    for j in range(0,m):
        print(end=" ")
    m=m-1
    for j in range(0,i+1):
        q=word[a]
        print(q, end=" ")
        a+=1
    a=0
    print(" ")
print("HACKTOBERFEST 2022!")
