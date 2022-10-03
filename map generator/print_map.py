a = 10
b = 0
c = 10

s = ("TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs"
     " UJq TNn*RPn/QPbEWS_JSWQAIJO^NBELPe"
     "HBFHT}TnALVlBLOFAkHFOuFETpHCStHAUFA"
     "gcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm S"
     "On TNn ULo0ULo#ULo-WHq!WFs XDt!")

a = ord(s[b])

while a != 0:
    if b < 170:
        a = ord(s[b])
        b += 1

        while a > 64:
            a -= 1
            c += 1

            if c == 90:
                c = c // 9
                print(end=chr(c))
            else:
                print(chr(33 ^ (b & 0X01)), end='')
    else:
        break