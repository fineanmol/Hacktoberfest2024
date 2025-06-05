n=list(map(int, input().split()))
search = int(input())
opena = True
for i in range(len(n)):
    if search==n[i]:
        print("Element found at ",i+1," position")
        opena = False
        break
if opena:
    print("Element not found")