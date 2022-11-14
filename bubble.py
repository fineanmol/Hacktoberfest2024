try:
    data = input("Enter comma-separated items of the list: ")
    data = list(map(int, data.split(',')))
    aux = data[0]
    for index in range(len(data) - 1):
        if data[index] > data[index+1]:
            aux = data[index+1]
            data[index+1] = data[index]
            data[index] = aux

    print(" The sorted list is: {}".format(data))
except:
    print("Input with wrong format")
    

    