
#simple division


def is_divided(num,divider):
    if ((num%divider) == 0):
        print ("the num "+str(num)+" is divided by "+ str(divider))
        return (True)
    else:
        print ("the num "+str(num)+" is NOT divided by "+ str(divider))
        return (False)


#examples:
is_divided(8,2)
is_divided(8,3)