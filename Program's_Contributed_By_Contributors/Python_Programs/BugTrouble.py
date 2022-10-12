#!/bin/python3

vol_kaefer = 0.0002
vol_kaefer_gesammt = 2
wochen = 0
anzahl_kaefer = 0
anzahl_kaefer_start = 0 

def eingabe(bar):
    foo = input(f"Bitte gib mir einen Wert für {bar} an.: ")
    return check_input(foo, bar)

def error_input(foo, bar):
    print(f"{foo} ist keine gültige Eingabe für {bar}.")
    print(f"Bitte gib mir einen validen Wert an.")

def check_input(foo, bar):
    try:
        foo = float(foo)
        if foo > 0:
            return foo
        else:
            error_input(foo, bar)
            return eingabe(bar)
    except:
        error_input(foo, bar)
        return eingabe(bar)

def check_kaefer(foo):
    if foo >= 2:
        return foo
    else:
        print(f"Damit sich die Käfer vermehren können müssen es mindestens 2 sein.")
        return check_kaefer(eingabe("die aktuelle Anzahl der Käfer"))

def rechne(foo, bug):
    global vol_kaefer_gesammt
    global wochen
    global anzahl_kaefer
    anzahl_kaefer = anzahl_kaefer_start
    float(foo)
    float(vol_kaefer_gesammt)
    vol_kaefer_gesammt = vol_kaefer * anzahl_kaefer_start
    while vol_kaefer_gesammt <= foo:
        wochen += 1
        anzahl_kaefer = anzahl_kaefer + (anzahl_kaefer * 0.95)
        vol_kaefer_gesammt = anzahl_kaefer * vol_kaefer
        #print("In Woche {} haben wir {:.0f} Käfer mit einem Volumen von {:.2f}.".format(wochen, anzahl_kaefer, vol_kaefer))
    return wochen

def main():
    global anzahl_kaefer_start
    anzahl_kaefer_start = check_kaefer(eingabe("die aktuelle Anzahl der Käfer"))
    vol = eingabe("das Volumen in M²")
    bar = rechne(vol, anzahl_kaefer)
    print(f"Bei einem Volumen von {vol_kaefer} benötigen {anzahl_kaefer_start:.0f} Käfer {bar} Wochen um den Raum zu füllen.")
    print(f"Außerdem hast du dann {anzahl_kaefer:.0f} dort.")

main()
