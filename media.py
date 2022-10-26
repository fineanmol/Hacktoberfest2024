from funcoes import *
while True:
    aluno=[]
    mediac=[]
    nome = input("Digite o nome do aluno: ")
    nota1 = int(input("Digite sua nota: "))
    nota2 = int(input("Digite sua segunda nota: "))
    resultado = media(nota1, nota2)
    adicionar_aluno = input("Deseja adicionar um novo aluno? ")
    aluno.append(nome)
    mediac.append(resultado)
    if adicionar_aluno in "nao,Nao":
        break
print(aluno,mediac)
