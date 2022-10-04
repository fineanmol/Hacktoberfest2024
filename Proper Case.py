# Write your code here :-)
def properCase(s,N):
    i = 0
    b = ""
    while i < N:
        if i == 0:
            if ord(s[i]) >= ord("a") and ord(s[i]) <= ord("z"):
                b = b + chr(ord(s[i]) - ord("a") + ord("A"))
        elif s[i] == " " or s[i] == ".":
            b = b + s[i]
            i = i + 1
            b = b + chr((ord(s[i]) - ord("a")) + ord("A"))
        elif (s[i] >= ("A")) and (s[i] <= ("Z")):
            b = b + chr(ord(s[i]) + ord("a") - ord("A"))
        else:
            b = b + s[i]
        i = i + 1
    return b
def main():
    s = str(input("Enter any string:"))
    N = len(s)
    print(properCase(s, N))
main()