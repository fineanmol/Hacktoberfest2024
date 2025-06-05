import re
plate = input("Enter the number plate:")
if re.match('[A-Z]{2}[0-9]{2}([A-Z]?[A-Z])[0-9]{4}$',plate):
    p = plate[2]
    q = plate[3]
    r = p+q
    s = plate[6]
    t = plate[7]
    u = plate[8]
    v = plate[9]
    w = s+t+u+v
    if(r=="00" or w=="0000"):
        print("Invalid")
        exit(0)
    else:
        print("Valid")
else:
    print("invalid")
    exit(0)
a = plate[0]
b = plate[1]
s = a+b
statedict= {"MH": "Maharashtra","AP":"Andrapradesh","PB":"Punjab","DH":"Delhi","KA":"Karnataka","GA":"Goa","TN":"Tamil Nadu",
            "KL":"Kerla","TE":"Telangana","AS":"Assam","OD":"Odisha","JK":"Jammu and Kashmir","RJ":"Rajasthan","GJ":"Gujrat",
            "MP":"Madhya Pradesh","AN":"Andaman Nicobar","CH":"Chandigarh","ML":"Meghalay","MN":"Manipur","NL":"Nagaland",
            "MZ":"Mizoram"}
if s in statedict:
    print(statedict[s])
else:
  print("State code does not match.")
