def insertionsort(A):
    #we start loop at second element (index 1) since the first item is already sorted
    for j in range(1,len(A)):
        key = A[j] #The next item we are going to insert into the sorted section of the array

        i = j-1 #the last item we are going to compare to
        #now we keep moving the key back as long as it is smaller than the last item in the array
        while (i > -1) and key < A[i]: #if i == -1 means that this key belongs at the start
            A[i+1]=A[i] #move the last object compared one step ahead to make room for key
            i=i-1 #observe the next item for next time.
        #okay i is not greater than key means key belongs at i+1
        A[i+1] = key
    return A



if __name__=="__main__":
    x = [5,2,4,6,1,3]
    insertionsort(x)
    print x
