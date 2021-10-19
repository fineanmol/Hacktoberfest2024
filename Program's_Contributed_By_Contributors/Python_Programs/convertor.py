s = int(input("Enter Seconds: "))
m = 0
h = 0
if s < 60:
    m = 0
    h = 0
if s >= 60:
    m = s//60
    s = s % 60
    h = 0
    if m >= 60:
        h = m//60
        m = m%60

print(f"Hour = {h}, Minute = {m}, Second = {s}")
    