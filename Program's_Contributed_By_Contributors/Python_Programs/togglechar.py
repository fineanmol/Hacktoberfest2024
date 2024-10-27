String = 'GuDDuBHaiyA'
String1 = str()
for i in String:
    if i.isupper():
        i = i.lower()
        String1 = String1 + i
    else:
        i = i.upper()
        String1 = String1 + i

print(String + ' after changing ' + String1)
