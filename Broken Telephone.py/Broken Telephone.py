# cook your dish here

#1 1 1 3 3 3 2

#return 4

#basically get the preceeding and succeeding number of both the ends.



#step = "5 5 5 5" # --> 4

#		1 3 1 1 1 --> 3

t = int(input(""))



for _ in range(t):

	l = int(input(""))

	step = list(map(int,input("").split(" ")))



	present = step[0] 

	count = 0



	for a in range(len(step)):

		if step[a] != present or (a!= l-1 and step[a] != step[a+1]):

			count+=1

			#print(step[a],a) #2,3,5,6

			present = step[a]



	print(count)





