oglst = []

inp = "hello world and practice makes perfect and hello world again Happy Hacktober Fest Fest"
e = inp.split()
for i in e:
    oglst.append(i)

ndlst = []
for i in oglst:
    if i not in ndlst:
	    ndlst.append(i)

ndlst.sort()
print(ndlst)
