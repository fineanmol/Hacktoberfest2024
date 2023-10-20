import time
import os

def a():
    os.system("clear")
a()

#------------------------------------# 
def monter(EtageHomme,EtageAcenseur):
    a()
    while EtageAcenseur < EtageHomme:
        print(f"etage n°{EtageAcenseur}")
        time.sleep(1)
        EtageAcenseur=EtageAcenseur+1
    print(f"vous etes au {EtageAcenseur}° etage ")
    return appel(EtageHomme,EtageAcenseur)
#----------------------------------------#

def descendre(EtageHomme,EtageAcenseur):
    a()
    direction ="bottom"
    while EtageAcenseur > EtageHomme:
        print(f"etage n°{EtageAcenseur}")
        time.sleep(1)
        EtageAcenseur=EtageAcenseur-1
    print(f"vous etes au {EtageAcenseur}° etage ")
    return appel(EtageHomme,EtageAcenseur)
#-----------------------------------------#
def appel(EtageHomme,EtageAcenseur):
    
    EtageAcenseur=EtageAcenseur
    EtageHomme =int(input("où voulez vous allez??? \n>>>"))
    while (EtageHomme < -5 ) or (EtageHomme > 15) :
        print("cette etage n'existe pas ")
        appel(EtageHomme,EtageAcenseur)
    if EtageHomme == EtageAcenseur:
        print(f"vous etes deja au {EtageAcenseur}° etage")
        EtageHomme =int(input("où voulez vous allez???\n>>>"))
        if EtageAcenseur < EtageHomme:
            monter(EtageHomme,EtageAcenseur)
        else:
            descendre(EtageHomme,EtageAcenseur)
    elif EtageAcenseur < EtageHomme:
        monter(EtageHomme,EtageAcenseur)
    else:
        descendre(EtageHomme,EtageAcenseur)
    
#-------------------------------------#
def initial():
   
    EtageAcenseur=0
    EtageHomme =int(input("où voulez vous allez???\n>>>"))
    while (EtageHomme < -5 ) or (EtageHomme > 15) :
        print("cette etage n'existe pas ")
        initial()
    if EtageHomme == EtageAcenseur:
        print(f"vous etes deja au {EtageAcenseur}° etage")
        initial()
        if EtageAcenseur < EtageHomme:
            monter(EtageHomme,EtageAcenseur)
        else:
            descendre(EtageHomme,EtageAcenseur)
    elif EtageAcenseur < EtageHomme:
        monter(EtageHomme,EtageAcenseur)
    else:
        descendre(EtageHomme,EtageAcenseur)
initial()

        
