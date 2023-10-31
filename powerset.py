def powset(l):
    if len(l)==1:
        return [[],l]
    else:
        return powset(l[1:]) + [[l[0]]+x for x in powset(l[1:])]


            


print(powset([1,2,3])[1:])
