def bubbleSort(arr):
    print(arr)
    for i in range(len(arr)-1):
        for j in range(len(arr)-1):
            if(arr[j] > arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    print(arr)                
    return arr

def main():    
    arr = []
    print("Size: ")
    n = int(input())
    print("Enter Array: ")
    for i in range(n):
        ch = int(input())
        arr.append(ch)
    arr = bubbleSort(arr)
    for i in arr:
        print(str(i), end=" ")


if __name__ == "__main__":
    main()
