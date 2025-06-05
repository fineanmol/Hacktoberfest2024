def soma_intervalo(x,y):
    intervalo=[]
    somador=0
    for c in range(x,y+1):
        intervalo.append(c)
    
    for x in range(len(intervalo)):
        somador += intervalo[x]
    return somador
