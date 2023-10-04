import random

print('\n')
alfabeto_maiusculo = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
alfabeto_minusculo = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
numeros = ['0','1','2','3','4','5','6','7','8','9']
simbolos = ['*','/','.','?','[]',';','@','!','$','#','^','%','&','+','-']

resposta_positiva = ['s','sim','ok','S']
resposta_negativa = ['n','N','não']

incluir = input("Incluir Simbolos? (s/n) ")

if incluir in resposta_positiva:	
	caracteres = alfabeto_maiusculo + alfabeto_minusculo + numeros + simbolos
elif incluir in resposta_negativa:
	caracteres = alfabeto_maiusculo + alfabeto_minusculo + numeros

print('\n')

tamanho = int(input('Tamanho da senha: '))

n = 0
senha = ""
index = len(caracteres)

while tamanho != n:
	senha = senha + caracteres[random.randint(0,index - 1)]		
	n = n + 1

print('\n')
print(senha)