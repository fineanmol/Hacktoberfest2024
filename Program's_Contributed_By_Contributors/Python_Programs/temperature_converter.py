def CelciusToKelvin(c):
    return c+273.15

def KelvinToCelcius(k):
    return k-273.15

def CelciusToFahrenheit(c):
    return 1.8*c+32

def FahrenheitToCelcius(f):
    return (f-32)/1.8

def FahrenheitToKelvin(f):
    return CelciusToKelvin(FahrenheitToCelcius(f))

def KelvinToFahrenheit(k):
    return CelciusToFahrenheit(KelvinToCelcius(k))

print("-----TEMPERATURE CONVERTER-----")

print("Options")
print("1. C->K\n2. K->C\n3. C->F\n4. F->C\n5. F->K\n6. K->C\n0. EXIT")
print("----------\n")

ftoc = list()
ftok = list()
ctof = list()
ctok = list()
ktoc = list()
ktof = list()

ch = int(input("Enter your choice : "))

while(ch>0):
    if(ch==1):
        c = float(input("Enter temperature in celcius : "))
        k = CelciusToKelvin(c)
        ctok.append((c,k))
        print("Celcius to Kelvin converion history : ", sorted(ctok))

    if(ch==2):
        k = float(input("Enter temperature in kelvin : "))
        c = KelvinToCelcius(k)
        ktoc.append((k,c))
        print("Kelvin to celcius conversion history : ", sorted(ktoc))
    
    if(ch==3):
        c = float(input("Enter temperature in celcius : "))
        f = CelciusToFahrenheit(c)
        ctof.append((c,f))
        print("Celcius to fahrenheit conversion history : ", sorted(ctof))
    
    if(ch==4):
        f = float(input("Enter temperature in fahrenheit : "))
        c = FahrenheitToCelcius(f)
        ftoc.append((f,c))
        print("Fahrenheit to celcius conversion history : ", sorted(ftoc))
    
    if(ch==5):
        f = float(input("Enter temperature in fahrenheit : "))
        k = FahrenheitToKelvin(f)
        ftok.append((f,k))
        print("Fahrenheit to kelvin conversion history : ", sorted(ftok))
    
    if(ch==6):
        k = float(input("Enter temperature in kelvin : "))
        f = KelvinToFahrenheit(k)
        ktof.append((k,f))
        print("Kelvin to fahrenheit conversion history : ", sorted(ktof))
    
    if(ch>=7):
        print("Invalid choice")

    print("\n----------\n")    
    ch = int(input("Enter choice : "))

print("BYE")
print("----------")
