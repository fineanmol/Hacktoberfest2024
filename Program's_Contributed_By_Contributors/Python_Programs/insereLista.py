def atribuir_valor_lista_vazia(lista, referencia):
    for i in referencia:
        lista.append(i)



def limpar_lista(lista):
    for i in range(len(lista)):
        lista.pop()
    return lista

def insere_na_fila(fila, nome, altura):
    valor = (nome,altura)
    nova_lista = []
    contador = 0

    for i in fila:
        if (altura < i[1] and contador < 1):
            nova_lista.append(valor)
            nova_lista.append(i)
            contador += 1
        else:
            nova_lista.append(i)
    
    if contador == 0:
        nova_lista.append(valor)

    if len(fila) == 1:
        nova_lista.pop()
        if (altura < i[1] and contador < 1):
            nova_lista.append(valor)
            nova_lista.append(i)
            contador += 1
        else:
            nova_lista.append(i)
            nova_lista.append(valor)

    limpar_lista(fila)
    fial = atribuir_valor_lista_vazia(fila, nova_lista)


