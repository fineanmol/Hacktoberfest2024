def valor_minimo(lista):
    valor_inicial = lista[0]
    for i in lista:
        if i < valor_inicial:
            valor_inicial = i
    
    return valor_inicial

def limpar_lista(lista):
    for i in range(len(lista)):
        lista.pop()
    return lista

def valor_maximo(lista):
    valor_inicial = lista[0]
    for i in lista:
        if i > valor_inicial:
            valor_inicial = i
    
    return valor_inicial


def negativos_no_fim(fila):
    nova = []


