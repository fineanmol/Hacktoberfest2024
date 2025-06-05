def pr_N_mostFrequentNumber(arr, N, K):

    mp = {}
    for i in range(N):
        if arr[i] in mp:
            mp[arr[i]] += 1
        else:
            mp[arr[i]] = 1
    a = [0] * (len(mp))
    j = 0
    for i in mp:
        a[j] = [i, mp[i]]
        j += 1
    a = sorted(a, key=lambda x: x[0],
               reverse=True)
    a = sorted(a, key=lambda x: x[1],
               reverse=True)

    # Display the top k numbers
    print(K, "numbers with most occurrences are:")
    for i in range(K):
        print(a[i][0], end=" ")


# Driver code
if __name__ == "__main__":
    arr = [3, 1, 4, 4, 5, 2, 6, 1]
    N = 8
    K = 2

    # Function call
    pr_N_mostFrequentNumber(arr, N, K)
