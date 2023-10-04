import random

# Função para gerar um número aleatório entre minimo e maximo (inclusos)
def aleatorio(minimo, maximo):
    return random.randint(minimo, maximo)

# Sorteia a porta que contém o prêmio
porta_premiada = aleatorio(1, 3)

# O participante escolhe uma porta
porta_escolhida = int(input("Escolha uma porta (1, 2 ou 3): "))

# O apresentador abre uma das portas que não contém o prêmio
if porta_premiada != porta_escolhida:
    # Se o participante não escolheu a porta premiada, o apresentador abre a porta que não contém o prêmio e que não foi escolhida
    porta_aberta = 6 - porta_premiada - porta_escolhida
else:
    # Se o participante escolheu a porta premiada, o apresentador abre uma das outras portas aleatoriamente
    porta_aberta = aleatorio(1, 3)
    while porta_aberta == porta_escolhida or porta_aberta == porta_premiada:
        porta_aberta = aleatorio(1, 3)

# Pergunta ao participante se ele deseja trocar de porta
troca_porta = int(input("A porta " + str(porta_aberta) + " contém uma cabra.2\nDeseja trocar de porta (1 para sim, 0 para não)? "))

# Verifica se o participante ganhou o prêmio
if troca_porta == 1:
    # O participante escolhe uma nova porta
    porta_escolhida = 6 - porta_escolhida - porta_aberta

if porta_escolhida == porta_premiada:
    print("Parabéns! Você ganhou o prêmio!")
else:
    print("Que pena, você não ganhou o prêmio.\nA porta premiada era a", porta_premiada, ".")
