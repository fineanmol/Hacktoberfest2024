# Questão "Sobre os Menores das Triplas"
# gabriel.santos.alves@ccc.ufcg.edu.br

def valor_minimo(lista):
    valor_inicial = lista[0]
    for i in lista:
        if i < valor_inicial:
            valor_inicial = i
    
    return valor_inicial


def valor_maximo(lista):
    valor_inicial = lista[0]
    for i in lista:
        if i > valor_inicial:
            valor_inicial = i
    
    return valor_inicial


def media(lista):
    valor_total = 0
    for i in lista:
        valor_total += i
    media = valor_total/len(lista)
    
    return media

def main():
    valores_tripla = []
    valores_menores = []

    while True:
        valor_entrada = input()
        if valor_entrada == 'fim':
            break
        teste = valor_entrada.split()
        if teste[0] == teste[1] and teste[1] == teste[2]:
            break
        else:
            for i in valor_entrada.split():
                valores_tripla.append(int(i))

            valores_menores.append(valor_minimo(valores_tripla))
            valores_tripla = []

    if valores_menores == []:
        media_menores = 'nada'
        menor_entre_menores = 'nada'
        maior_entre_menores = 'nada'
        
        print(f"Média dos menores: {media_menores}")
        print(f"Menor entre os menores: {menor_entre_menores}")
        print(f"Maior entre os menores: {maior_entre_menores}")
    else:
        media_menores = media(valores_menores)
        menor_entre_menores = valor_minimo(valores_menores)
        maior_entre_menores = valor_maximo(valores_menores)

        print(f"Média dos menores: {media_menores:.2f}")
        print(f"Menor entre os menores: {menor_entre_menores:.0f}")
        print(f"Maior entre os menores: {maior_entre_menores:.0f}")


    return None


