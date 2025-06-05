# Function to find the longest common substring of sequences `X[0…m-1]` and `Y[0…n-1]`
def LCS(X, Y, m, n):
 
    maxLength = 0           # stores the max length of LCS
    endingIndex = m         # stores the ending index of LCS in `X`
 
    # `lookup[i][j]` stores the length of LCS of substring `X[0…i-1]` and `Y[0…j-1]`
    lookup = [[0 for x in range(n + 1)] for y in range(m + 1)]
 
    # fill the lookup table in a bottom-up manner
    for i in range(1, m + 1):
        for j in range(1, n + 1):
 
            # if the current character of `X` and `Y` matches
            if X[i - 1] == Y[j - 1]:
                lookup[i][j] = lookup[i - 1][j - 1] + 1
 
                # update the maximum length and ending index
                if lookup[i][j] > maxLength:
                    maxLength = lookup[i][j]
                    endingIndex = i
 
    # return longest common substring having length `maxLength`
    return X[endingIndex - maxLength: endingIndex]
 
 
if __name__ == '__main__':
 
    X = 'ABC'
    Y = 'BABA'
 
    m = len(X)
    n = len(Y)
 
    # Find longest common substring
    print('The longest common substring is', LCS(X, Y, m, n))
