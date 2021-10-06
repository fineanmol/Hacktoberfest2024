# Python function for the problem of Tower of Hanoi 

def TowerOfHanoi(n , from_rod, to_rod, aux_rod): 
	if n == 1: 
		print "Move disk 1 from rod",from_rod,"to rod",to_rod 
		return
	TowerOfHanoi(n-1, from_rod, aux_rod, to_rod) 
	print "Move disk",n,"from rod",from_rod,"to rod",to_rod 
	TowerOfHanoi(n-1, aux_rod, to_rod, from_rod) 
		
# driver code
n = 4
TowerOfHanoi(n, 'a', 'c', 'b') 

#contributed by AnushkaGarg26