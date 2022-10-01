def getSubstr(string, alpha):
    seen = {} # create a hashmap to store the alphabets records
    for c in alpha:  # create keys and assign default values for a key to 0
        seen[c] = 0
    seen[string[0]] = 1  # assign count 1 to the first letter in hashmap
    start, end = 0, 0
    shortest_s, shortest_e = 0, 99999
    while end + 1 < len(string):  # iterating until and unless end pointer reaches to the end of the string
        print(seen, string[shortest_s:shortest_e + 1], start, end)
        while seen[string[start]] > 1:  # check if the occurance of letters in hashmap (since given string does not contain repeatitive letters)
            seen[string[start]] -= 1  # decrease count by 1
            start += 1  # increment start pointer by 1
        if sum(seen.values()) == len(alpha) and all(v == 1 for v in seen.values()) and \
                shortest_e - shortest_s > end-start:
            """
            check if total hashmap count is == length of given alphabets substring AND
            if all values in hashmaps are 1 for each key AND
            the difference between end and start should be less than shortest_s & shortest_e pointers
            """
            shortest_s = start
            shortest_e = end
        end +=1   # increment end pointer by 1
        seen[string[end]] += 1   # increment the count of character in hashmap by 1
    return string[shortest_s:shortest_e+1]


print(getSubstr("abbcbacaabcababcabccabaabc", "acb"))
