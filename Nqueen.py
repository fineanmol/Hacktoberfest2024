global N
N = 16
global L
L = [-1 for x in range(N)]

def is_safe(row, col):
    for x in range(row):
        c2 = L[x]
        if(c2 >= 0 and c2 == col):
            return False
        if(c2 >= 0 and abs(col - c2) == abs(x - row)):
            return False
    return True

def it(row):
    if(row >= N):
        return True

    for i in range(N):
        if(is_safe(row, i)):
            L[row] = i
            if(it(row + 1)):
                return True
            L[row] = -1
    return False

if(it(0)):
	for i in range(len(L)):
		print("(" + str(i) + ", " + str(L[i]) + ") ", end='')
	print()
	for i in range(N):
		for j in range(N):
			if(j in L and L[i] == j):
				print("Q\t", end='')
			else:
				print(".\t", end='')
		print()
else:
	print("No sequence found...");
